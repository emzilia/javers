#include <iostream>
#include <vector>
#include <filesystem>

std::vector<std::string> jvm_dirs;
std::vector<std::string>::iterator ji;

const std::string JVM_LIB_PATH = "/usr/lib/jvm/";
const std::string JAVA_HOME_VAR = "JAVA_HOME";
const std::string JAVA_DEFAULT_PATH = "/usr/lib/jvm/default";
const std::string JAVA_DEFAULT_RUNTIME_PATH = "/usr/lib/jvm/default-runtime";

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
		std::cout << "Error: Invalid selection" << std::endl;
		std::exit(1);
	}

	std::string selection = jvm_dirs.at(response - 1);
	std::string full_path =  JVM_LIB_PATH + selection;
	std::cout << full_path << std::endl;

	std::filesystem::remove_all(JAVA_DEFAULT_PATH);
	std::filesystem::remove_all(JAVA_DEFAULT_RUNTIME_PATH);
	std::filesystem::create_directory_symlink(full_path, JAVA_DEFAULT_PATH);
	std::filesystem::create_directory_symlink(full_path, JAVA_DEFAULT_RUNTIME_PATH);
}
