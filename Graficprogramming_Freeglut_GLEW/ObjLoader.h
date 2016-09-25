#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

#include "Object.h"

#include "Vector.h"


class ObjLoader
{
public:
	std::string name;
	std::vector <Vector> vertices;
	std::vector <Vector> uvs;
	std::vector <Vector> normals;

	std::vector <Vector> V_indeces;
	std::vector <Vector> UV_indices;
	std::vector <Vector> N_indices;

	std::vector<Object> objects;

	ObjLoader();
	bool loadObject(char* path);
	int loadAllObjects(char* path);

	void printObj();

	~ObjLoader();
};

