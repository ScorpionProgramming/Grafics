#include "ObjLoader.h"
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
					Vector vertex;
					fscanf(file, "%f %f %f/n", &vertex.x, &vertex.y, &vertex.z);
					this->vertices.push_back(vertex);
				}
			//wenn erster string ein 'VT' ist dann:
				else if (strcmp(letter, "vt") == 0) {
					Vector uv;
					fscanf(file, "%f %f %f/n", &uv.x, &uv.y);
					this->uvs.push_back(uv);
				}
				//wenn erster string ein 'VN' ist dann:
				else if (strcmp(letter, "vn") == 0) {
					Vector normal;
					fscanf(file, "%f %f %f/n", &normal.x, &normal.y, &normal.z);
					this->normals.push_back(normal);
				}
				else if (strcmp(letter, "f") == 0) {
					int match;
					Vector vIndex;
					Vector uvIndex;
					Vector nIndex;
					match = fscanf(file, "%f %f %f\n", vIndex.x, vIndex.y, vIndex.z);
					if (match != 3) {
						match = fscanf(file, "%f/%f %f/%f %f/%f\n", vIndex.x, nIndex.x, vIndex.y, nIndex.y, vIndex.z, nIndex.z);
						if (match != 6) {
							match = fscanf(file, "%f//%f %f//%f %f//%f\n", vIndex.x, nIndex.x, vIndex.y, nIndex.y, vIndex.z, nIndex.z);
							if (match != 6) {
								match = fscanf(file, "%f//%f %f//%f %f//%f\n", vIndex.x, nIndex.x, vIndex.y, nIndex.y, vIndex.z, nIndex.z);
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
	/*std::vector <Vector> vertices = this->objects[0].getVertices();
	for (int i = 0; i < vertices.size(); i++) {
		Vector vertex = vertices[i];
		std::cout << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
	}*/
}


ObjLoader::~ObjLoader()
{
}
