#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class IOManager
{
public:
	IOManager() {}

	static std::string readFile(const std::string& filePath);

private:
	static std::ifstream inputStream;
};