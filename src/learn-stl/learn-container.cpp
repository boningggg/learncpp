#include <array>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <unordered_set>

auto learn_array() -> void;
auto learn_unordered_set() -> void;
auto learn_queue() -> void;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: learn-container INPUT" << std::endl;
		return 0;
	}

	auto target = argv[1];
	if (std::strcmp(target, "array") == 0) {
		learn_array();
	} else if (std::strcmp(target, "unordered_set") == 0) {
		learn_unordered_set();
	} else if (std::strcmp(target, "queue") == 0) {
		learn_queue();
	} else {
		std::cerr << target
			  << " is not a container or is not learned(will be "
			     "learned in the future. I promise..)"
			  << std::endl;
	}

	return 0;
}

auto learn_array() -> void
{
	std::cout << "0. Create an array: intArrray with [1,2,3,4,5]."
		  << std::endl;
	auto intArray = std::array<int, 5>{1, 2, 3, 4, 5};

	std::cout << "1. Check its capacity." << std::endl;
	std::cout << "   Is empty(1 true, 0 false): " << intArray.empty()
		  << std::endl;
	std::cout << "   Size: " << intArray.size() << std::endl;
	std::cout << "   Max size: " << intArray.max_size() << std::endl;

	std::cout << "2. Element access." << std::endl;
	std::cout << "   intArray.at(0) is " << intArray.at(0) << std::endl;
	std::cout << "   intArray[0] is " << intArray[0] << std::endl;
	std::cout << "   intArray.front() is " << intArray.front() << std::endl;
	std::cout << "   intArray.back() is " << intArray.back() << std::endl;

	std::cout << "3. Access position out of bounds." << std::endl;
	std::cout << "   intArray.at(666)" << std::endl;
	try {
		intArray.at(666) = 666;
		;
	} catch (std::out_of_range const &exc) {
		std::cout << "   Error " << exc.what() << std::endl;
	}

	std::cout << "4. Iterator" << std::endl;
	std::cout << "   ";
	for (auto const &e : intArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::cout << "5. fill()" << std::endl;
	intArray.fill(100);
	std::cout << "   ";
	for (auto const &e : intArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::cout << "6. swap()" << std::endl;
	auto otherArray = std::array<int, 5>({101, 102, 103, 104, 105});
	std::cout << "   Before" << std::endl;
	std::cout << "   intArray: ";
	for (auto const &e : intArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << "   otherArray: ";
	for (auto const &e : otherArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << "   After" << std::endl;
	intArray.swap(otherArray);
	std::cout << "   intArray: ";
	for (auto const &e : intArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << "   otherArray: ";
	for (auto const &e : otherArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

auto learn_unordered_set() -> void
{
	std::cout << "0. Create an unordered_set: stringSet." << std::endl;
	auto stringSet = std::unordered_set<std::string>();

	std::cout << "1. Check its capacity." << std::endl;
	std::cout << "   Is empty(1 true, 0 false): " << stringSet.empty()
		  << std::endl;
	std::cout << "   Size: " << stringSet.size() << std::endl;

	std::cout << "2. Insert elements." << std::endl;
	std::cout << "   apple" << std::endl;
	std::cout << "   banana" << std::endl;
	std::cout << "   watermelon" << std::endl;
	std::cout << "   orange" << std::endl;
	stringSet.insert("apple");
	stringSet.insert("banana");
	stringSet.insert("watermelon");
	stringSet.insert("orange");

	std::cout << "3. Check its capacity again and print all the elements."
		  << std::endl;
	std::cout << "   Is empty(1 true, 0 false): " << stringSet.empty()
		  << std::endl;
	std::cout << "   Size: " << stringSet.size() << std::endl;
	std::cout << "   Elements: " << std::endl;
	for (auto const &element : stringSet) {
		std::cout << "     " << element << std::endl;
	}

	std::cout << "4. Find one(not exist in the stringSet)." << std::endl;
	auto find_one = stringSet.find("one");
	if (find_one != stringSet.end()) {
		std::cout << "   Found " << *find_one << std::endl;
	} else {
		std::cout << "   Not Found one" << std::endl;
	}

	std::cout << "5. Find apple(exist in the stringSet)." << std::endl;
	auto find_apple = stringSet.find("apple");
	if (find_apple != stringSet.end()) {
		std::cout << "   Found " << *find_apple << std::endl;
	} else {
		std::cout << "   Not Found apple" << std::endl;
	}
}

auto learn_queue() -> void
{
	std::cout << "0. Create a queue: stringQueue." << std::endl;
	auto stringQueue = std::queue<std::string>();

	std::cout << "1. Check its capacity." << std::endl;
	std::cout << "   Is empty(1 true, 0 false): " << stringQueue.empty()
		  << std::endl;
	std::cout << "   Size: " << stringQueue.size() << std::endl;

	std::cout << "2. Push elements." << std::endl;
	std::cout << "   apple" << std::endl;
	std::cout << "   banana" << std::endl;
	std::cout << "   watermelon" << std::endl;
	std::cout << "   orange" << std::endl;
	stringQueue.push("apple");
	stringQueue.push("banana");
	stringQueue.push("watermelon");
	stringQueue.push("orange");

	std::cout << "3. Check its capacity again." << std::endl;
	std::cout << "   Is empty(1 true, 0 false): " << stringQueue.empty()
		  << std::endl;
	std::cout << "   Size: " << stringQueue.size() << std::endl;

	std::cout << "4. Print its first element and the last element."
		  << std::endl;
	std::cout << "   The first element is " << stringQueue.front()
		  << std::endl;
	std::cout << "   The last element is " << stringQueue.back()
		  << std::endl;

	std::cout << "5. Pop all the elements until the queue is empty."
		  << std::endl;
	while (!stringQueue.empty()) {
		std::cout << "   Pop element " << stringQueue.front()
			  << std::endl;
		stringQueue.pop();
	}

	std::cout << "6. Check its capacity again." << std::endl;
	std::cout << "   Is empty(1 true, 0 false): " << stringQueue.empty()
		  << std::endl;
	std::cout << "   Size: " << stringQueue.size() << std::endl;
}
