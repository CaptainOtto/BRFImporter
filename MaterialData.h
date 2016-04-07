#pragma once

#ifndef MATERIALDATA_H
#define MATERIALDATA_H

class MaterialData
{
private:

public:
	void DiffuseMap();

	void SpecularMap();

	void GlossMap();

	void NormalMap();

	void GlowMap();

	MaterialData();

	~MaterialData();
};
#endif