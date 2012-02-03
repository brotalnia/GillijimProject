#ifndef MCIN_H_
#define MCIN_H_

#include <vector>
#include <iostream>
#include "Chunk.h"

class Mcin : public Chunk
{
    public:

	Mcin();
	Mcin(const std::vector<char> & fullAdtData, int position, int sizeAdjustments);
	Mcin(std::string letters, int givenSize, const std::vector<char> & chunkData);
	std::vector<int> getMcnkOffsets() const;
	friend std::ostream & operator<<(std::ostream & os, const Mcin & mcin);
};

#endif