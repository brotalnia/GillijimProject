#ifndef ADTCATA_H_
#define ADTCATA_H_

#include <vector>
#include <string>
#include "../Chunk.h"
#include "../Mhdr.h"
#include "McnkCata.h"
#include "McnkCataTex0.h"
#include "McnkCataObj0.h"

class AdtCata
{
	public:

		AdtCata(const std::string & adtFile);
		std::string getTex0FileName() const;
		std::string getObj0FileName() const;
		friend std::ostream & operator<<(std::ostream & os, const AdtCata & adtCata);

	private:

		std::string adtName;

		Chunk terrainMver;
		Mhdr mhdr;
		Chunk mh2o;
		std::vector<McnkCata> terrainMcnks;
		Chunk mfbo;

		Chunk tex0Mver;
		Chunk mamp;
		Chunk mtex;
		std::vector<McnkCataTex0> tex0Mcnks;
		/*Chunk mtxf;

		Chunk obj0Mver;
		Chunk mmdx;
		Chunk mmid;
		Chunk mwmo;
		Chunk mwid;
		Chunk mmdf;
		Chunk modf;
		std::vector<McnkCataObj0> obj0Mcnks;*/
};

#endif