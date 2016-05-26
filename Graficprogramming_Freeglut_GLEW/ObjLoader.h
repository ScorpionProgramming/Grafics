#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Object.h"

class ObjLoader
{
public:
	std::string name;
	std::vector <vec3> vertices;
	std::vector <vec2> uvs;
	std::vector <vec3> normals;

	std::vector <vec3> V_indeces;
	std::vector <vec3> UV_indices;
	std::vector <vec3> N_indices;

	std::vector<Object> objects;

	ObjLoader();
	bool loadObject(char* path);
	int loadAllObjects(char* path);

	void printObj();

	~ObjLoader();
};

