#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

class ShaderLoader
{
public:
	ShaderLoader(void);
	~ShaderLoader(void);
	GLuint CreateProgramm(char* VertexShaderFilename, char* FragmentShaderFilename);
private:
	std::string ReadShader(char* filename);
	GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);
};

