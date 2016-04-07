#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class MeshData : Fetch
	{
	private:


	public:
		void OOBBData();

		void IndexData();

		void VertexData();

		MeshData();

		~MeshData();

	};
}