#include <iostream>
#include <string>
#include <vector>
int main (int argc, char *argv[])
{
	auto a = std::vector<std::vector<std::string>> {};
	auto b = std::vector<std::string> {"a", "b"};

	a.push_back(b);
	b.push_back("c");
	b.pop_back();
	for (auto const& v : a) {
		for (auto const&  e: v) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	for (auto const& e: b) {
		std::cout << e << " ";
	}
	std::cout << std::endl;


	return 0;
}
