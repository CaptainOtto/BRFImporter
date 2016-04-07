#include "LightData.h"

BRFImporter::SpotLightHeader BRFImporter::LightData::SpotLightData()
{
	return this->spotLightData;
}

<<<<<<< HEAD
BRFImporter::AmbLightHeader BRFImporter::LightData::AmbLightData()
{
	return this->ambLightData;
}

BRFImporter::AreaLightHeader BRFImporter::LightData::AreaLightData()
{
	return this->areaLightData;
}

BRFImporter::PointLightHeader BRFImporter::LightData::PointLightData()
{
	return this->pointLightData;
}

BRFImporter::DirLightHeader BRFImporter::LightData::DirLightData()
{
	return this->dirLightData;
}

BRFImporter::LightData::LightData(SpotLightHeader spotLightData, AmbLightHeader ambLightData, AreaLightHeader areaLightData, PointLightHeader pointLightData, DirLightHeader dirLightData)
{
	this->spotLightData = spotLightData;
	this->ambLightData = ambLightData;
=======
BRFImporter::AreaLightHeader BRFImporter::LightData::AreaLightData()
{
	return this->areaLightData;
}

BRFImporter::PointLightHeader BRFImporter::LightData::PointLightData()
{
	return this->pointLightData;
}

BRFImporter::DirLightHeader BRFImporter::LightData::DirLightData()
{
	return this->dirLightData;
}

BRFImporter::LightData::LightData(SpotLightHeader spotLightData, AreaLightHeader areaLightData, PointLightHeader pointLightData, DirLightHeader dirLightData)
{
	this->spotLightData = spotLightData;
>>>>>>> refs/remotes/origin/Otto-branch
	this->areaLightData = areaLightData;
	this->pointLightData = pointLightData;
	this->dirLightData = dirLightData;
}
//CON
BRFImporter::LightData::LightData()
<<<<<<< HEAD
{

}
//DECON
BRFImporter::LightData::~LightData()
=======
>>>>>>> refs/remotes/origin/Otto-branch
{

}
//DECON
BRFImporter::LightData::~LightData()
{

}