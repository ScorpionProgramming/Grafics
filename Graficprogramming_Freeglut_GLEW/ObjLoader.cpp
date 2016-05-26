#include "ObjLoader.h"

#include "vec3.h"
#include "vec2.h"
#include <iostream>

ObjLoader::ObjLoader()
{
}

bool ObjLoader::loadObject(char* path)
{
	FILE *file = fopen(path, "r"); //file mit dem parameter READ oefnen
	int result;
	if (file == NULL) {
		std::cout << "Datei kann nicht geoeffnet werden" << std::endl;
		return false;
	}
	else {
		Object obj;
		do {
			char letter[128];
			result = fscanf(file, "%s", letter);

			if (strcmp(letter, "o") == 0) {
				char name[128];
				fscanf(file, "%s_\n", name);
				this->name = name;
			}
			else
				//wenn erster string ein 'V' ist dann:
				if (strcmp(letter, "v") == 0) {
					vec3 vertex;
					fscanf(file, "%f %f %f/n", &vertex.X, &vertex.Y, &vertex.Z);
					this->vertices.push_back(vertex);
				}
			//wenn erster string ein 'VT' ist dann:
				else if (strcmp(letter, "vt") == 0) {
					vec2 uv;
					fscanf(file, "%f %f %f/n", &uv.X, &uv.Y);
					this->uvs.push_back(uv);
				}
				//wenn erster string ein 'VN' ist dann:
				else if (strcmp(letter, "vn") == 0) {
					vec3 normal;
					fscanf(file, "%f %f %f/n", &normal.X, &normal.Y, &normal.Z);
					this->normals.push_back(normal);
				}
				else if (strcmp(letter, "f") == 0) {
					int match;
					vec3 vIndex;
					vec3 uvIndex;
					vec3 nIndex;
					match = fscanf(file, "%f %f %f\n", vIndex.X, vIndex.Y, vIndex.Z);
					if (match != 3) {
						match = fscanf(file, "%f/%f %f/%f %f/%f\n", vIndex.X, nIndex.X, vIndex.Y, nIndex.Y, vIndex.Z, nIndex.Z);
						if (match != 6) {
							match = fscanf(file, "%f//%f %f//%f %f//%f\n", vIndex.X, nIndex.X, vIndex.Y, nIndex.Y, vIndex.Z, nIndex.Z);
							if (match != 6) {
								match = fscanf(file, "%f//%f %f//%f %f//%f\n", vIndex.X, nIndex.X, vIndex.Y, nIndex.Y, vIndex.Z, nIndex.Z);
								if (match != 9) {
									printf("File can't be read by our simple parser : ( Try exporting with other options\n");
									return false;
								}
							}
						}
					}
					this->V_indeces.push_back(vIndex);
					this->UV_indices.push_back(uvIndex);
					this->N_indices.push_back(nIndex);
				}
		} while (result != EOF);
		this->objects.push_back(obj);
	}
}

int ObjLoader::loadAllObjects(char* path)
{
	return 0;
}

void ObjLoader::printObj()
{
	std::vector <vec3> vertices = this->objects[0].getVertices();
	for (int i = 0; i < vertices.size(); i++) {
		vec3 vertex = vertices[i];
		std::cout << vertex.X << " " << vertex.Y << " " << vertex.Z << std::endl;
	}
}


ObjLoader::~ObjLoader()
{
}
