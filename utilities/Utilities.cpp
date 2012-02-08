#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Utilities.h"

namespace Utilities
{
	int getIntFromCharVector(const std::vector<char> & someData, int offset)
	{
		std::vector<char>::const_iterator dataIter;
		char curValues[4];
		int i = 0;
	
		for (dataIter = someData.begin() + offset ; dataIter != someData.begin() + offset + 4 ; ++dataIter)
		{
			curValues[i] = *dataIter;
			i++;
		}
		memcpy(&offset, curValues, sizeof(offset));
	
		return offset;
	}

	float getFloatFromCharVector(const std::vector<char> & someData, int offset)
	{
		float result;
		std::vector<char>::const_iterator dataIter;
		char curValues[4];
		int i = 0;
	
		for (dataIter = someData.begin() + offset ; dataIter != someData.begin() + offset + 4 ; ++dataIter)
		{
			curValues[i] = *dataIter;
			i++;
		}
		memcpy(&result, curValues, sizeof(result));
	
		return result;
	}

	std::string getStringFromCharVector(const std::vector<char> & someData, int start, int stringLength)
	{
		std::string letters = "";
	
		std::vector<char>::const_iterator adtIter;
		for (adtIter = someData.begin() + start ; adtIter != someData.begin() + start + stringLength ; ++adtIter)
		{
			letters = letters + *adtIter;
		}
		return letters;
	}

	std::vector<char> getCharSubVector(const std::vector<char> & someData, int start, int length)
	{
		std::vector<char> subVector;
		std::vector<char>::const_iterator dataIter;

		for (dataIter = someData.begin() + start ; dataIter != someData.begin() + start + length ; ++dataIter)
		{
			subVector.push_back(*dataIter);
		}

		return subVector;
	}

  std::string getLettersFromFile(std::ifstream & adtFile, int position)
  {
    std::string letters = "";

    adtFile.seekg(position, std::ios::beg);
    char lettersBuffer[4];
    adtFile.read(lettersBuffer, 4);

    int i;
    for (i = 0 ; i < sizeof(lettersBuffer) ; i++)
    {
      letters = letters + lettersBuffer[i];
    }
    return letters;
  }

  int getIntFromFile(std::ifstream & adtFile, int position)
  {
    int givenSize = 0;

    adtFile.seekg(position, std::ios::beg);
    char sizeBuffer[4];
    adtFile.read(sizeBuffer, 4);

    memcpy(&givenSize, sizeBuffer, sizeof(givenSize));

    return givenSize;
  }

  std::vector<char> getCharVectorFromFile(std::ifstream & adtFile, int position, int length)
  {
    std::vector<char> data(0);

    adtFile.seekg(position, std::ios::beg);
    char * dataBuffer;
    dataBuffer = new char[length];
    adtFile.read(dataBuffer, length);

    int i;
    for (i = 0 ; i < sizeof(dataBuffer) ; i++)
    {
      data.push_back(dataBuffer[i]);
    } 

    delete[] dataBuffer;

    return data;
  }
}