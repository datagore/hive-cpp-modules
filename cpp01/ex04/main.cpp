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

	// Open the file for reading, starting at the end of the file.
	std::fstream file(filename, std::ios::in | std::ios::ate);
	if (!file.is_open()) {
		std::cout << "error: can't open file: " << filename << std::endl;
		return 1;
	}

	// Read the contents of the whole file into a string.
	std::string input(file.tellg(), 0);
	file.seekg(0);
	if (!file.read(input.data(), input.size())) {
		std::cout << "error: can't read file: " << filename << std::endl;
		return 1;
	}

	// Open the output file, truncating any existing file contents.
	file.close();
	file.open(filename + ".replace", std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		std::cout << "error: can't open file: " << filename << std::endl;
		return 1;
	}

	// Find occurrences of s1 in the input.
	if (!s1.empty()) {
		size_t pos = 0;
		while (pos < input.length()) {
			size_t found = input.find(s1, pos);

			// When s1 is found in the input, write everything up to that point
			// to the output, and then write s2 instead of s1.
			if (found != input.npos) {
				file.write(input.data() + pos, found - pos);
				file.write(s2.data(), s2.length());
				pos = found + s1.length();

			// If s1 couldn't be found, write the rest of the input directly to
			// the output.
			} else {
				file.write(input.data() + pos, input.length() - pos);
				pos = input.length();
			}
		}
	}
}
