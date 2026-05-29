#include <iostream>
#include <vector>
#include <filesystem>

std::vector<std::string> jvm_dirs;
std::vector<std::string>::iterator ji;

const std::string JVM_LIB_PATH = "/usr/lib/jvm/";

int main() {
	for (const auto & entry : std::filesystem::directory_iterator(JVM_LIB_PATH)) {
		if (entry.is_directory()) {
			std::string path = entry.path().stem();
			if (path.compare(0, 7, "default")) jvm_dirs.push_back(path);
		}
	}

	std::cout << "Select the version to set:" << std::endl;
	int i = 0;
	for (ji = jvm_dirs.begin(); ji != jvm_dirs.end(); ++ji) {
		i++;

		std::cout << i << ". " << *ji << std::endl;
	}

	long unsigned int response;
	std::cin >> std::setw(1) >> response;

	if (response > jvm_dirs.size() || response < 1) {
		std::cout << "Error: Invalid size" << std::endl;
		std::exit(1);
	}
	
	std::cout << JVM_LIB_PATH << jvm_dirs.at(response - 1) << std::endl;
}
