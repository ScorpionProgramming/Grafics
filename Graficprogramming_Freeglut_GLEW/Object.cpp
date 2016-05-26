#include "Object.h"



Object::Object()
{

}

Object::~Object()
{
}

std::string Object::getName()
{
	return name;
}

std::vector<vec3> Object::getVertices()
{
	return vertices;
}

std::vector<vec2> Object::getUV()
{
	return uvs;
}

std::vector<vec3> Object::getNormals()
{
	return normals;
}

void Object::setName(std::string name)
{
	this->name = name;
}

void Object::addVertex(vec3 vertex)
{
	vertices.push_back(vertex);
}

void Object::addUV(vec2 uv)
{
	uvs.push_back(uv);
}

void Object::addNormal(vec3 normal)
{
	normals.push_back(normal);
}

void Object::addVertexIndex(vec3 v_index)
{
	V_indeces.push_back(v_index);
}

void Object::addUVIndex(vec3 uv_index)
{
	UV_indices.push_back(uv_index);
}

void Object::addNormalIndex(vec3 n_index)
{
	N_indices.push_back(n_index);
}
