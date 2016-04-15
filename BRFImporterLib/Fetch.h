#pragma once
#include "MeshData.h"
#include <vector>
#include "LightData.h"

namespace BRFImporterLib
{
	class FetchContainer
	{
	private:
		std::shared_ptr<MainHeader> mainData;
		std::vector<std::shared_ptr<MeshData>> meshes;
	public:
		MainHeader* getMain();
		//CONDECON
		FetchContainer(std::shared_ptr<MainHeader> mainData, std::vector<std::shared_ptr<MeshData>> meshVector);
		~FetchContainer();
	};

	class Fetch
	{
	
	private:
		std::shared_ptr<FetchContainer> FetchDataContainer;
	public:
		MainHeader* Main();
		MeshData* Mesh(unsigned int meshID);
		//LightData* Light(unsigned int lightID);

		//CON DECON
		Fetch(std::shared_ptr<FetchContainer> fileFetch);

		Fetch();
		~Fetch();

	};
}
