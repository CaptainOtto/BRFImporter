#include "GroupData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

using namespace BRFImporterLib;



GroupHeader * BRFImporterLib::GroupData::getGroupData()
{
	return this->groupData.get();
}

//CON DECON
GroupData::GroupData()
{
}


GroupData::~GroupData()
{
}

