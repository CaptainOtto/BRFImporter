#pragma once
#include "Fetch.h"

namespace BRFImporterLib
{
	class MeshData : Fetch
	{
	protected:
		int B;
		MeshData();
	public:
		~MeshData();
	};
}