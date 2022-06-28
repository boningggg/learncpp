#include <algorithm>
#include <array>
#include <iostream>

auto learn_all_any_none_of() -> void;

int main(int argc, char *argv[])
{
	learn_all_any_none_of();
	return 0;
}

auto learn_all_any_none_of() -> void
{
	auto intArray =
	    std::array<int, 10>({2, 4, 6, 8, 10, 12, 14, 16, 18, 20});

	std::cout << "The array is ";
	for (auto const &e : intArray) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::cout << "All the values are even(1 true, 0 false): "
		  << std::all_of(intArray.begin(), intArray.end(),
				 [](int i) { return i % 2 == 0; })
		  << std::endl;

	std::cout << "None of the values are odd(1 true, 0 false): "
		  << std::none_of(intArray.begin(), intArray.end(),
				  [](int i) { return i % 2 == 1; })
		  << std::endl;

	std::cout << "Any of the values is divisible by 7(at least one value): "
		  << std::any_of(intArray.begin(), intArray.end(),
				 [](int i) { return i % 7 == 0; })
		  << std::endl;
}
