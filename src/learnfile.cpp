#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string   filename = "test0";
	std::ifstream in;
	std::ofstream out;

	std::cout << "0. Open a file test0(does not exist)." << std::endl;
	{
		std::filesystem::remove(filename);
		in = std::ifstream(filename);
		if (!in.is_open()) {
			std::cout << "   File test0 does not exist."
				  << std::endl;
		}
		in.close();
	}

	std::cout << "1. Create the file test0." << std::endl;
	{
		out = std::ofstream(filename);
		if (!out.is_open()) {
			std::cout << "   Can not create the file test0."
				  << std::endl;
		} else {
			std::cout << "   Succeed." << std::endl;
		}
		out.close();
	}

	std::cout << "2. Read the content of the file test0(does not have any "
		     "content now)."
		  << std::endl;
	{
		in = std::ifstream(filename);
		if (in.is_open()) {
			std::string line;
			while (std::getline(in, line)) {
				std::cout << line << std::endl;
			}
			in.close();
		}
	}

	std::cout << "3. Write some content to the file test0." << std::endl;
	{
		out = std::ofstream(filename);
		std::cout << "   1 One\n"
			  << "   2 Two\n"
			  << "   3 Three\n";
		out << "   1 One\n";
		out << "   2 Two\n";
		out << "   3 Three\n";
		out.close();
	}

	std::cout << "4. Read test0 again." << std::endl;
	{
		in = std::ifstream(filename);
		if (in.is_open()) {
			std::string line;
			while (std::getline(in, line)) {
				std::cout << line << std::endl;
			}
			in.close();
		}
	}

	return 0;
}
