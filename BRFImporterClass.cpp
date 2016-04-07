#include "BRFImporterClass.h"
#include "Fetch.h"
#include "BRFImporterStructs.h"
#include "targetver.h"
#include <stdio.h>
#include <string.h>


void BRFImporter::BRFImporterClass::setFilePath(char newFilePath[])
{
	memcpy(this->filePath, newFilePath, sizeof(char) * 256);
		
}
char BRFImporter::BRFImporterClass::getFileName()
{
	return this->fileName[256];
}




//CON
BRFImporter::BRFImporterClass::BRFImporterClass(char fileName[])
{
	memcpy(this->fileName, fileName, sizeof(char) * 256);
}
BRFImporter::BRFImporterClass::BRFImporterClass()
{

}
//DECON
BRFImporter::BRFImporterClass::~BRFImporterClass()
{

}






BRFImporter::BRFImporterClass DataStorage

BRFImporter::DataContainer->filepath("filepath") ; //motor tar minnet, DataCOntainer är en constructor som läser in filen i fråga och "dynamiskt fyller DataStorage med data från filen

BRFImporter::DataContainer Datastorage = "filepath"

DataStorage.Fetch->Meshdata().getIndexData();




