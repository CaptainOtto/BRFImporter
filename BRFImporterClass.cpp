#include "BRFImporterClass.h"
#include "Fetch.h"
#include "BRFImporterStructs.h"
#include "targetver.h"
#include <stdio.h>

//void BRFImporter::BRFImporterClass::setFilePath(std::string newFilePath)
//{
//	this->filePath = newFilePath;	
//}
//std::string BRFImporter::BRFImporterClass::getFileName()
//{
//	return this->fileName;
//}




//CON Assign BRF file here
BRFImporter::BRFImporterClass::BRFImporterClass(std::string newFileName)
{
	
}
BRFImporter::BRFImporterClass::BRFImporterClass()
{

}
//DECON
BRFImporter::BRFImporterClass::~BRFImporterClass()
{

}





std::string test = "hej";
BRFImporter::BRFImporterClass DataStorage(test);

BRFImporter::DataContainer->filepath("filepath") ; //motor tar minnet, DataCOntainer är en constructor som läser in filen i fråga och "dynamiskt fyller DataStorage med data från filen

BRFImporter::DataContainer Datastorage = "filepath";

DataStorage.Fetch->Meshdata().getIndexData();




