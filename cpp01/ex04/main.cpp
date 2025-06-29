#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	// Get command line arguments.
	if (argc != 4) {
		std::cout << "usage: " << argv[0] << " <file> <search> <replace>\n";
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Open the file for reading and writing, at the end of the file.
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::ate);
	if (!file.is_open()) {
		std::cout << "error: can't open file: " << filename << std::endl;
		return 1;
	}

	// Read the contents of the whole file into a string.
	std::string contents(file.tellg(), 0);
	file.seekg(0);
	if (!file.read(contents.data(), contents.size())) {
		std::cout << "error: can't read file: " << filename << std::endl;
		return 1;
	}

	// Replace every occurrence of s1 with s2.
	file.seekp(0);
	size_t pos = 0;
	if (!s1.empty()) {
		while (pos < contents.length()) {
			size_t found = contents.find(s1, pos);
			if (found != contents.npos) {
				file.write(contents.data() + pos, found - pos);
				file.write(s2.data(), s2.length());
				pos = found + s1.length();
			} else {
				file.write(contents.data() + pos, contents.length() - pos);
				pos = contents.length();
			}
		}
	}
}
