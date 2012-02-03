#include <vector>
#include <string>
#include "../Chunk.h"
#include "Monm.h"
#include "../../utilities/Utilities.h"

Monm::Monm() : Chunk()
{
}

Monm::Monm(const std::vector<char> & fullAdtData, int position, int sizeAdjustments) : Chunk(fullAdtData, position, sizeAdjustments)
{
}

Monm::Monm(std::string letters, int givenSize, const std::vector<char> & data) : Chunk("NIAM", givenSize, data) 
{
}

Chunk Monm::toMwmo()
{
	Chunk mwmoLk = Chunk("OMWM", givenSize, data);
	return mwmoLk;
}