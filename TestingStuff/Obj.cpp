#include "Obj.h"



Obj::Obj()
{
}


Obj::~Obj()
{
}

bool Obj::loadObject(char * path)
{
	FILE *file = fopen(path, "r"); //file mit dem parameter READ oefnen
	int result;
	if (file == NULL) {
		std::cout << "Datei kann nicht geoeffnet werden" << std::endl;
		return false;
	}
	else {
		std::cout << "Datei wurde geöffnet!" << std::endl;
		do {
			char letter[128];
			result = fscanf(file, "%s", letter);
			if (strcmp(letter, "o") == 0) {
				fscanf(file, "%s_%s\n", this->name);
			}
			else if(strcmp(letter, "v") == 0){
				vec3 vertex;
				fscanf(file, "%f %f %f/n", &vertex.X, &vertex.Y, &vertex.Z);
				this->vertices.push_back(vertex);
			}
			else if (strcmp(letter, "vt") == 0) {
				vec2 uv;
				fscanf(file, "%f %f/n", &uv.X, &uv.Y);
				this->uvs.push_back(uv);
			}
			else if (strcmp(letter, "vn") == 0) {
				vec3 normal;
				fscanf(file, "%f %f %f/n", &normal.X, &normal.Y, &normal.Z);
				this->normals.push_back(normal);
			}
			else if (strcmp(letter, "f") == 0) {
				int match;
				vec3 vIndex = { 0,0,0 };
				vec3 uvIndex = { 0,0,0 };
				vec3 nIndex = { 0,0,0 };

				match = fscanf(file, "%f//%f %f//%f %f//%f", &vIndex.X, &nIndex.X, &vIndex.Y, &nIndex.Y, &vIndex.Z, &nIndex.Z);
				if (match == 1) {
					match = fscanf(file, "%f/%f %f/%f/%f %f/%f/%f", &uvIndex.X, &nIndex.X, &vIndex.Y, &uvIndex.Y, &nIndex.Y, &vIndex.Z, &uvIndex.Z, &nIndex.Z);
					if (match == 0) {
						match = fscanf(file, "%f %f", &vIndex.X, &vIndex.Y, &vIndex.Z);
						if (match == 0) {
							match = fscanf(file, "%f %f/%f %f/%f", &vIndex.X, &nIndex.X, &vIndex.Y, &nIndex.Y, &vIndex.Z, &nIndex.Z);
						}
					}
				}
				else if (match != 6 && match != -1) {
					printf("File can't be read by our simple parser : ( Try exporting with other options\n");
					return false;
				}
				/*
					match = fscanf(file, "%f//%f %f//%f %f//%f", &vIndex.X, &nIndex.X, &vIndex.Y, &nIndex.Y, &vIndex.Z, &nIndex.Z);
					match = fscanf(file, "%f/%f/%f %f/%f/%f %f/%f/%f", &vIndex.X, &uvIndex.X, &nIndex.X, &vIndex.Y, &uvIndex.Y, &nIndex.Y, &vIndex.Z, &uvIndex.Z, &nIndex.Z);
					match = fscanf(file, "%f %f %f", &vIndex.X, &vIndex.Y, &vIndex.Z);
					match = fscanf(file, "%f/%f %f/%f %f/%f", &vIndex.X, &nIndex.X, &vIndex.Y, &nIndex.Y, &vIndex.Z, &nIndex.Z);
				*/
				this->V_indices.push_back(vIndex);
				this->UV_indices.push_back(uvIndex);
				this->N_indices.push_back(nIndex);
			}
		} while (result != EOF);
		this->V_indices.pop_back();
		this->UV_indices.pop_back();
		this->N_indices.pop_back();
	}

	std::cout << "\n\n\n\nDatei Name: "<<this->name << std::endl;

	std::cout << "\n\n+++++ VERTICES +++++ " << std::endl;
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << vertices[i].X << " " << vertices[i].Y << " " << vertices[i].Z << std::endl;
	}
	std::cout << "\n\n+++++ NORMALS +++++ " << std::endl;
	for (int i = 0; i < normals.size(); i++) {
		std::cout << normals[i].X << " " << normals[i].Y << " " << normals[i].Z << std::endl;
	}
	std::cout << "\n\n+++++ UV_COORDINATES +++++ " << std::endl;
	for (int i = 0; i < uvs.size(); i++) {
		std::cout << uvs[i].X << " " << uvs[i].Y  << std::endl;
	}
	std::cout << "\n\n+++++ VERTEX_INDICES +++++ " << std::endl;
	for (int i = 0; i < V_indices.size(); i++) {
		std::cout << V_indices[i].X << " " << V_indices[i].Y << " " << V_indices[i].Z << std::endl;
	}
	std::cout << "\n\n+++++ NORMAL_INDICES +++++ " << std::endl;
	for (int i = 0; i < N_indices.size(); i++) {
		std::cout << N_indices[i].X << " " << N_indices[i].Y << " " << N_indices[i].Z << std::endl;
	}

	std::cout << "\n\n+++++ UV_INDICES +++++ " << std::endl;
	for (int i = 0; i < UV_indices.size(); i++) {
		std::cout << UV_indices[i].X << " " << UV_indices[i].Y << " " << UV_indices[i].Z << std::endl;
	}

	std::cout << "\n\n " <<	name		<< std::endl;
	std::cout << vertices.size() * 3	<< "\n" << std::endl;
	std::cout << normals.size() * 3		<< "\n" << std::endl;
	std::cout << uvs.size() * 3			<< "\n" << std::endl;
	std::cout << V_indices.size() * 3	<< "\n" << std::endl;
	std::cout << N_indices.size() * 3	<< "\n" << std::endl;
	std::cout << UV_indices.size() * 3	<< "\n" << std::endl;
	std::cout <<"GESAMTGROESSE\n" << std::endl;
	std::cout << sizeof(name) + sizeof(vertices) + sizeof(normals) + sizeof(uvs) + sizeof(V_indices) + sizeof(N_indices) + sizeof(UV_indices) << "Bytes"<< std::endl;

}
