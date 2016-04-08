#pragma once
#include "Fetch.h"

namespace BRFImporterLib
{
	class MeshData : Fetch
	{
	protected:
		int B;
	public:
		int getA();
		int getB();
		MeshData();
		~MeshData();
	};
}