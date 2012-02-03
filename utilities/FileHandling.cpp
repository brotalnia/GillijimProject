#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stdexcept>
#include "FileHandling.h"

FileHandling::FileHandling(const std::string &fName) : fileName(fName)
{
}

std::vector<char> FileHandling::getFullFile()
{
	std::ifstream::pos_type fileSize;
	
	std::ifstream file (fileName.c_str(), std::ios::in|std::ios::binary);
	if(!file)
	{
		throw std::runtime_error("Unable to open file");
	}
	
	char curByte;
	std::vector<char> fullFile;

	while (file.get(curByte))
	{
		fullFile.push_back(curByte);
	}

	file.close();
	return fullFile;
}

void FileHandling::toBinFile(const std::vector<char> & binData)
{	
	std::ofstream outputFile(fileName.c_str(), std::ios::out|std::ios::app|std::ios::binary);
	if (!outputFile)
	{
		throw std::runtime_error("Unable to create file");
	}

	outputFile.is_open();
	// TODO
	outputFile.close();
}