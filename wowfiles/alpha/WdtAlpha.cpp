#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "WdtAlpha.h"
#include "MphdAlpha.h"
#include "../Wdt.h"
#include "AdtAlpha.h"
#include "Monm.h"
#include "../Chunk.h"
#include "MainAlpha.h"
#include "../../utilities/Utilities.h"

WdtAlpha::WdtAlpha(const std::string & wdtAlphaName) : wdtName(wdtAlphaName)
{
  std::ifstream wdtAlphaFile;
  wdtAlphaFile.open(wdtAlphaName, std::ios::binary);

  const int chunkLettersAndSize = 8;
  const int mdnmOffset = 4;
  const int monmOffset = 12;

  int offsetInFile = 0;

  mver = Chunk(wdtAlphaFile, offsetInFile);
  offsetInFile = chunkLettersAndSize + offsetInFile + mver.getGivenSize();

  const int MphdStartOffset = offsetInFile + chunkLettersAndSize;

  mphd = MphdAlpha(wdtAlphaFile, offsetInFile);
  offsetInFile = chunkLettersAndSize + offsetInFile + mphd.getGivenSize();

  main = MainAlpha(wdtAlphaFile, offsetInFile);
  offsetInFile = chunkLettersAndSize + offsetInFile + main.getGivenSize(); 

  offsetInFile = Utilities::getIntFromFile(wdtAlphaFile, MphdStartOffset + mdnmOffset);
  mdnm = Chunk(wdtAlphaFile, offsetInFile);

  offsetInFile = Utilities::getIntFromFile(wdtAlphaFile, MphdStartOffset + monmOffset);
  monm = Monm(wdtAlphaFile, offsetInFile);	

  offsetInFile = chunkLettersAndSize + offsetInFile + monm.getGivenSize();

  if (mphd.isWmoBased())
  {
    modf = Chunk(wdtAlphaFile, offsetInFile);
    offsetInFile = chunkLettersAndSize + offsetInFile + modf.getGivenSize(); 
  }

  /*std::vector<int> adtsOffsets = main.getMhdrOffsets();
  int currentAdt;

  for (currentAdt = 0 ; currentAdt < 4096 ; currentAdt++)
  {	
    if (adtsOffsets[currentAdt] != 0)
    {
      offsetInFile = adtsOffsets[currentAdt];
      adts.push_back(AdtAlpha(wdtAlphaFile, offsetInFile, currentAdt));
    }
  }*/
}

Wdt WdtAlpha::toWdt()
{
  std::string name = "__testWdtLk.wdt";

  Mphd cMphd = mphd.toMphd();
  Main cMain = main.toMain();

  std::vector<char> emptyData(0);
  Chunk cMwmo = Chunk("OMWM", 0, emptyData);
  Chunk cModf = Chunk();

  if (mphd.isWmoBased())
  {
    cMwmo = monm.toMwmo();
    cModf = modf;
  }

  Wdt wdtLk = Wdt(name, mver, cMphd, cMain, cMwmo, cModf);
  return wdtLk;
}

std::ostream & operator<<(std::ostream & os, const WdtAlpha & wdtAlpha)
{
  os << wdtAlpha.wdtName << std::endl;
  os << "------------------------------" << std::endl;
  os << wdtAlpha.mver;
  os << wdtAlpha.mphd;
  os << wdtAlpha.main;
  os << wdtAlpha.mdnm;
  os << wdtAlpha.monm;
  os << wdtAlpha.modf;

  /*std::vector<AdtAlpha>::const_iterator adtsIter;
  int i = 0;

  for (adtsIter = wdtAlpha.adts.begin() ; adtsIter != wdtAlpha.adts.end() ; ++adtsIter)
  {
    os << *adtsIter;
    i++;
  }*/

  return os;
}