#include "IOManager.h"

std::ifstream IOManager::inputStream;

std::string IOManager::readFile(const std::string &filePath) {
	inputStream.open(filePath, std::ios::binary);
	std::vector<char> contents;

	if (inputStream.fail()) {
		std::cout << "File not found: " + filePath + ".\n";
		exit(-1);
	}

	inputStream.seekg(0, std::ios::end);

	unsigned int fileSize = (unsigned int)inputStream.tellg();
	inputStream.seekg(0, std::ios::beg);

	fileSize -= (unsigned int)inputStream.tellg();

	contents.resize(fileSize);
	inputStream.read(&(contents[0]), fileSize);
	inputStream.close();

	std::string contentsStr(contents.begin(), contents.end());

	return contentsStr;
}
