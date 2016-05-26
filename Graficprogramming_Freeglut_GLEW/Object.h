#pragma once
#include <vector>
#include <string>

class Object
{
private:
	std::vector <vec3> vertices;
	std::vector <vec2> uvs;
	std::vector <vec3> normals;

	std::vector <vec3> V_indeces;
	std::vector <vec3> UV_indices;
	std::vector <vec3> N_indices;
public:
	std::string name;
	Object();
	~Object();
	std::string getName();
	std::vector<vec3> getVertices();
	std::vector<vec2> getUV();
	std::vector<vec3> getNormals();

	void setName(std::string name);
	void addVertex(vec3 vertex);
	void addUV(vec2 uv);
	void addNormal(vec3 normal);

	void addVertexIndex(vec3 v_index);
	void addUVIndex(vec3 uv_index);
	void addNormalIndex(vec3 n_index);
};

