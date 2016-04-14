#pragma once
#include "MeshData.h"
#include "LightData.h"

namespace BRFImporterLib
{
	struct FetchContainer
	{
		std::shared_ptr<MainHeader> mainData;
		std::unique_ptr<MeshData[]> meshes;
	};
	class Fetch
	{
	
	private:
		std::shared_ptr<FetchContainer> FetchDataContainer;
	public:
		MainHeader* Main();
		MeshData* Mesh(unsigned int meshID);
		LightData* Light(unsigned int lightID);

		//CON DECON
		Fetch(std::shared_ptr<FetchContainer> fileFetch);

		Fetch();
		~Fetch();

	};
}
