#include "FileData.h"
//#include "Fetch.h"
//#include "MeshData.h"
using namespace BRFImporterLib;

int main()
{
	FileData player;
	std::string filename = "playerfile.brf";
	player.LoadFile(filename, true, false);
	float exempel = player.fetch->Mesh(3)->GetVertexData()->pos[2];
	player.fetch->Mesh(2);
}
