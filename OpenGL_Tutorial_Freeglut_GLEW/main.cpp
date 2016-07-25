// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>
#include <GL/GL.h>
// Include GLFW
#include <GL/freeglut.h>


//shader
#include "ShaderLoader.h"

using namespace std;


GLuint program;


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.75, 0.75, 1.0, 1.0); //clearcolor

	//use the created program
	glUseProgram(program);

	//draw 3 vertices as triagle
	glDrawArrays(GL_TRIANGLES, 0, 12);

	glutSwapBuffers();
}

void Init() {
	glEnable(GL_DEPTH_TEST);
	
	//load and compile shaders
	ShaderLoader shaderLoader;
	program = shaderLoader.CreateProgramm("Vertex_Shader.glsl", "Fragment_Shader.glsl");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glewInit();
	
	Init();

	//register callbacks
	glutDisplayFunc(display);
	glutMainLoop();

	//delete 'programm' before closing
	glDeleteProgram(program);
	return 0;
}
