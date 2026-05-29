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
	for (ji = jvm_dirs.begin(); ji != jvm_dirs.end(); ++ji) {
		std::cout << *ji << std::endl;
	}
}
