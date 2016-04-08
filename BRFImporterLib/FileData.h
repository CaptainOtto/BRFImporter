#pragma once
#include <string>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class FileData
	{
	protected:

	public:
		void LoadFile(std::string fileName);

		//CON DECON
		FileData();
		~FileData();
	};
}