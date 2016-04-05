#pragma once

namespace BRFImporter
{
	//HEADER STRUCTS

	//Starting with Static
	struct MainHeader
	{
		bool lights;

		unsigned int meshAmount;
		unsigned int materialAmount;
		unsigned int cameraAmount;
		unsigned int skeletonAmount;
		unsigned int morphAnimAmount;
		unsigned int groupAmount;
		unsigned int attributeAmount;
	};
	struct MeshHeader
	{
		char meshName[256];
		unsigned int objectID;
		unsigned int parentID;		// 0 = Default

		unsigned int vertexCount;
		unsigned int indexCount;
		unsigned int materialID;

		unsigned int attrCount;		// 0 = Default
		
		bool boundingBox;
		
		double translation[3];
		double rotation[3];
		double scale[3];
	};
	struct MaterialHeader
	{
		unsigned int materialID;
		//TO BE CONTINUED
	};
	struct SkeletonHeader
	{
		unsigned int jointCount;
		unsigned int animationCount;
	};
	struct CameraHeader
	{
		unsigned int objectID;
		unsigned int parentID;		// 0 = Default

		double translation[3];
		double rotation[3];
		double viewDir[3];
	};
	struct LightHeader
	{
		unsigned int spotCount;
		unsigned int ambientCount;
		unsigned int directionalCount;
		unsigned int areaCount;
		unsigned int pointCount;
	};
	struct GroupHeader
	{
		char groupName[256];
		unsigned int objectID;
		unsigned int parentID;		// 0 = Default

		double translation[3];
		double rotation[3];
		double scale[3];
	};
	struct MorphAnimHeader
	{
		unsigned int vertices;
		unsigned int shapeID;
	};
	struct AtributeHeader
	{
		//TO BE CONTINUED
	};
	class BRFImporterClass
	{
	private:

	public:

	};
}