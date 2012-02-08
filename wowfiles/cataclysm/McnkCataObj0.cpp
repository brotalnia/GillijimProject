#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "../Chunk.h"
#include "McnkCataObj0.h"
#include "../../utilities/Utilities.h"

McnkCataObj0::McnkCataObj0(std::ifstream & adtFile, int offsetInFile) : Chunk(adtFile, offsetInFile)
{
  const int mcnkHeaderSize = 128;

  mcnkHeader = Utilities::getCharVectorFromFile(adtFile, offsetInFile, mcnkHeaderSize);
  offsetInFile = mcnkHeaderSize + 1;

  const int mcrdOffset = 0; // TODO (is there any ?)
  const int mcrwOffset = 0; // TODO (is there any ?)

  if (Utilities::getIntFromCharVector(mcnkHeader, mcrdOffset) != 0)
  {
    mcrd = Chunk(adtFile, offsetInFile); // TODO : check that...
    offsetInFile = offsetInFile + mcrd.getRealSize();
  }
  else
  {
    mcrd = Chunk();
  }

  if (Utilities::getIntFromCharVector(mcnkHeader, mcrwOffset) != 0)
  {
    mcrw = Chunk(adtFile, offsetInFile);
    offsetInFile = offsetInFile + mcrw.getRealSize();
  }
  else
  {
    mcrw = Chunk();
  }
}

McnkCataObj0::McnkCataObj0(const std::vector<char> & fullAdtData, int fullDataOffset, int sizeAdjustments) : Chunk(fullAdtData, fullDataOffset, sizeAdjustments)
{
  const int mcnkHeaderSize = 128;

  mcnkHeader = Utilities::getCharSubVector(fullAdtData, fullDataOffset, mcnkHeaderSize);
  fullDataOffset = mcnkHeaderSize + 1;

  const int mcrdOffset = 0; // TODO (is there any ?)
  const int mcrwOffset = 0; // TODO (is there any ?)

  if (Utilities::getIntFromCharVector(mcnkHeader, mcrdOffset) != 0)
  {
    mcrd = Chunk(data, fullDataOffset, sizeAdjustments);
    fullDataOffset = fullDataOffset + mcrd.getRealSize();
  }
  else
  {
    mcrd = Chunk();
  }

  if (Utilities::getIntFromCharVector(mcnkHeader, mcrwOffset) != 0)
  {
    mcrw = Chunk(data, fullDataOffset, sizeAdjustments);
    fullDataOffset = fullDataOffset + mcrw.getRealSize();
  }
  else
  {
    mcrw = Chunk();
  }
}