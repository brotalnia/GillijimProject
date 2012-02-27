#ifndef MCIN_H_
#define MCIN_H_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Chunk.h"

class Mcin : public Chunk
{
  public:

    Mcin();
    Mcin(std::ifstream & adtFile, int offsetInFile);
    Mcin(std::string letters, int givenSize, const std::vector<char> & chunkData);

    std::vector<int> getMcnkOffsets() const;
    friend std::ostream & operator<<(std::ostream & os, const Mcin & mcin);
};

#endif