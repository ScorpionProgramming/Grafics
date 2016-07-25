#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include <GL/glew.h>
#include <GL/freeglut.h>


using namespace std;
int drawMode = 0;
GLuint VBOID; //unsiged int in openGL kann auch normales 'unsigned int' sein

static const int SCREEN_WIDTH = 960;
static const int SCREEN_HEIGHT = 540;

static const char* titel = "3D Grafics (c)ScorpioN ";

float rot = 0;
float posZ = 0;
float posX = 0;

int frames = 0;
float base_time = 0;
float fps;
float time = 0;

int oldTime = 0;

float deltaTime = 0;


//kann auch ein ganz normaler float sein (fuer später vielleicht von vorteil)
static const GLfloat vertices[] =
{ 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
-1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
-1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

-1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
-1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

-1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
-1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4

static const GLfloat normals[] =
{ 0, 0, 1,   0, 0, 1,   0, 0, 1,    // v0-v1-v2 (front)
0, 0, 1,   0, 0, 1,   0, 0, 1,      // v2-v3-v0

1, 0, 0,   1, 0, 0,   1, 0, 0,      // v0-v3-v4 (right)
1, 0, 0,   1, 0, 0,   1, 0, 0,      // v4-v5-v0

0, 1, 0,   0, 1, 0,   0, 1, 0,      // v0-v5-v6 (top)
0, 1, 0,   0, 1, 0,   0, 1, 0,      // v6-v1-v0

-1, 0, 0,  -1, 0, 0,  -1, 0, 0,      // v1-v6-v7 (left)
-1, 0, 0,  -1, 0, 0,  -1, 0, 0,      // v7-v2-v1

0,-1, 0,   0,-1, 0,   0,-1, 0,      // v7-v4-v3 (bottom)
0,-1, 0,   0,-1, 0,   0,-1, 0,      // v3-v2-v7

0, 0,-1,   0, 0,-1,   0, 0,-1,      // v4-v7-v6 (back)
0, 0,-1,   0, 0,-1,   0, 0,-1 };    // v6-v5-v4

static const GLfloat colors[] =
{ 1, 1, 1,   1, 1, 0,   1, 0, 0,    // v0-v1-v2 (front)
1, 0, 0,   1, 0, 1,   1, 1, 1,      // v2-v3-v0

1, 1, 1,   1, 0, 1,   0, 0, 1,      // v0-v3-v4 (right)
0, 0, 1,   0, 1, 1,   1, 1, 1,      // v4-v5-v0

1, 1, 1,   0, 1, 1,   0, 1, 0,      // v0-v5-v6 (top)
0, 1, 0,   1, 1, 0,   1, 1, 1,      // v6-v1-v0

1, 1, 0,   0, 1, 0,   0, 0, 0,      // v1-v6-v7 (left)
0, 0, 0,   1, 0, 0,   1, 1, 0,      // v7-v2-v1

0, 0, 0,   0, 0, 1,   1, 0, 1,      // v7-v4-v3 (bottom)
1, 0, 1,   1, 0, 0,   0, 0, 0,      // v3-v2-v7

0, 0, 1,   0, 0, 0,   0, 1, 0,      // v4-v7-v6 (back)
0, 1, 0,   0, 1, 1,   0, 0, 1 };    // v6-v5-v4

static const GLfloat vertexIndices[]{
	0,0,0
};

static const GLfloat textures[] = {
		0
};


int vertexCount = sizeof(vertices) / sizeof(float) / 3;
int colorCount = sizeof(colors) / sizeof(float) / 3;

float speed = 10;

void keyboard(unsigned char key, int x, int y) {
	switch (key) 
	{
	case 27:
		exit(0);
		break;
	case 'w':
		posZ += speed*deltaTime;
		break;
	case 'a':
		posX += speed*deltaTime;
		break;
	case 's':
		posZ -= speed*deltaTime;
		break;
	case 'd':
		posX -= speed*deltaTime;
		break;
	case ' ':
		drawMode = ++drawMode % 2;
		cout << "Drawmode: "<< drawMode << endl;
		if (drawMode == 0) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
		}else{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDisable(GL_DEPTH_TEST);
			glDisable(GL_CULL_FACE);
		}
		break;
	default:
		;
	}


	if (key == 'c' || key == 'C') {
		cout << "Hallo Welt\n" << endl;
	}
}

void mouse(int button, int state, int x, int y) {

}

void drawString(const char* str, int x, int y, float color[4], void *font) {
	glPushAttrib(GL_LIGHTING_BIT | GL_CURRENT_BIT);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glColor4fv(color);
	glRasterPos2i(x, y);

	while (*str) {
		glutBitmapCharacter(font, *str);
		++str;
	}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopAttrib();
}


//funktion die beim pro frame einmal ausgeführt wird.
void display() {
	int start = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (float)start - oldTime;
	oldTime = start;
	deltaTime = deltaTime / 1000;

	//gibt die zeit aus, die seit dem start vergangen ist!
	//time = glutGet(GLUT_ELAPSED_TIME);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	rot +=0.5;

	glLoadIdentity();
	glTranslatef(posX, 0, posZ);
	glRotatef(rot, 1, 0, 0);
	glRotatef(rot, 0, 1, 0);
	//glRotatef(rot, 0, 0, 1);

	//enable funktionen
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glBindBuffer(GL_ARRAY_BUFFER, VBOID);

	glVertexPointer(3, GL_FLOAT, 0, 0); //(anz. punkte, datentyp, wie viele übersprungen werden sollen, wo starten(0 = lese von grafikkarte))
	glColorPointer(3, GL_FLOAT, 0, (void*)sizeof(vertices));

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//disable funktion
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);


	//#######################################################################
	//				SHOW INFOS
	//#######################################################################
	// backup current model-view matrix
	glPushMatrix();                     // save current modelview matrix
	glLoadIdentity();                   // reset modelview matrix

										// set to 2D orthogonal projection
	glMatrixMode(GL_PROJECTION);     // switch to projection matrix
	glPushMatrix();                  // save current projection matrix
	glLoadIdentity();                // reset projection matrix
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);  // set to orthogonal projection

	stringstream ss;
	ss << "Delta Time:" << deltaTime << " frames: " << round(1/deltaTime) << " fps: " << fps;

	float color[4] = { 1,1,1,1 }; 
	float color2[4] = { 1,1,0,1 };
	drawString(ss.str().c_str(), 0.5, SCREEN_HEIGHT - 13, color2, GLUT_BITMAP_8_BY_13);
	drawString("Hoffentlich stehe ich unter dem ersten String - Woops?", 0.5, SCREEN_HEIGHT - 13*2, color, GLUT_BITMAP_8_BY_13);
	drawString("Bin ich ein Text der Gelb ist?", 0.5, SCREEN_HEIGHT - 13 * 3, color, GLUT_BITMAP_8_BY_13);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	//#######################################################################
	//				SHOW INFOS END
	//#######################################################################

	glutSwapBuffers(); //erstellt das 'doublebffering'
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height); //gibt an wo auf dem bild gezeichnet werden soll

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float)(width) / height, 0.01f, 1000.0f);

	// switch to modelview matrix in order to set scene
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void initGL() {
	//color		  r	   g	b	 w
	glClearColor(0.1, 0.1, 0.1, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);

	//glewInit();
	if (glewInit()) {
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cerr << "GLEW initialized correct..." << endl;
	}

	if (glewIsSupported("GL_VERSION_4_3"))
	{
		cout << "GLEW Version is 4.3\n";
	}
	else
	{
		cout << "GLEW 4.3 not supported\n";
	}

	cout << "VerticesCount: " << vertexCount << endl;
	cout << "ColorCount: " << colorCount << endl;
	cout << "QuadSize = " << sizeof(vertices) + sizeof(colors) << " Bytes" << endl;

	//kopier daten an die g-karte
	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID); //bind buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)+sizeof(colors), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER_ARB, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER_ARB, sizeof(vertices), sizeof(colors), colors);
	glBindBuffer(GL_ARRAY_BUFFER, 0); //unbind buffer
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow(titel);
	
	initGL();
	
	glutReshapeFunc(reshape);
	//registered callback functions
	glutDisplayFunc(display); //eine funktion wird übergeben die jeden frame ausgeführt werden soll
	glutIdleFunc(display);

	//keyboard & mouse input handle
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}