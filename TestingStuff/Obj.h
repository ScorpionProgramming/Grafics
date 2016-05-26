#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <string>
#include <iostream>

class Obj
{
private:
	typedef struct vec3 {
		float X;
		float Y;
		float Z;
	}vec3;

	typedef struct vec2{
		float X; 
		float Y;
	}vec2;

public:
	Obj();
	~Obj();
	char name[128];
	std::vector <vec3> vertices;
	std::vector <vec2> uvs;
	std::vector <vec3> normals;

	std::vector <vec3> V_indices;
	std::vector <vec3> UV_indices;
	std::vector <vec3> N_indices;

	std::vector <Obj> objects;

	bool loadObject(char* path);
};

