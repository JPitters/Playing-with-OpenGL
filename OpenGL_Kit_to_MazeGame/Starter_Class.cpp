#include "SOIL.h"
#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Tank.h"
#include "Circle.h"
#include "Camera.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cone.h"
#include <string>
#include <ctime>

// ------------------------------------------ Stuff from Previous Project ---------------------------------
//Old Variables
/*
float rotateZ = 0.0f;
float rotateY = 0.0f;
float rotateX = 0.0f;
float rotateS = 0.0f;

float transZ = 0.0f;
float transY = 0.0f;
float transX = 0.0f;
//float rotateS = 0.0f;

float rotation_angle = 0.0f;
float x, y=0, move;
int oldTimeSinceStart = 0;

Camera* cam;
GLint windowWidth = 800;
GLint windowHeight = 600;

GLint midWindowX = windowWidth / 2;
GLint midWindowY = windowHeight / 2;

GLfloat fieldOfView = 45.0f;
GLfloat near = 0.01f;
GLfloat far = 150.0f;

GLuint texture[1];
*/

//Old controls
/*
void handleKeyPresses(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			cam->holdingForward = true;
			break;
		case 's':
			cam->holdingBackward = true;
			break;
		case 'a':
			cam->holdingLeftStrafe = true;
			break;
		case 'd':
			cam->holdingRightStrafe = true;
			break;

		case 't':
			rotateZ = 1;
			transZ += 0.1;

			break;
		case 'f':
			rotateX = 1;
			rotateS = 180;
			transX += 0.1;


			break;
		case 'g':
			rotateZ = 1;
			rotateS = 180;
			transZ -= 0.1;

			break;
		case 'h':
			transX -= 0.1;
			rotateS = 90;
			
			break;

		default:
			//do nothing
			break;
	}
}
void handleKeyReleased(unsigned char key, int x, int y)
{
	
	switch (key)
	{
	case 'w':
		cam->holdingForward = false;
		break;
	case 's':
		cam->holdingBackward = false;
		break;
	case 'a':
		cam->holdingLeftStrafe = false;
		break;
	case 'd':
		cam->holdingRightStrafe = false;
		break;

	case 't':
		rotateZ = 0;
		rotateS = 0;

		break;
	case 'f':
		rotateX = 0;
		rotateS = 0;

		break;
	case 'g':
		rotateZ = 0;

		break;
	case 'h':

		break;
	default:
		//do nothing
		break;
	}
}
void handleMouseMove(int button, int state, int x, int y)
{
	cam->handleMouseMove(x, y);
}
*/

//Old Draw, init, and idle functions
/*
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Ready to Draw
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glBegin(GL_LINE_STRIP);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0);

		
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 100, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 100);
		

	glEnd();
	
	
	glRotatef(cam->getRotation().x, 1.0f, 0.0f, 0.0f);  
	glRotatef(cam->getRotation().y, 0.0f, 1.0f, 0.0f);
	glTranslatef(-cam->getPosition().x, -cam->getPosition().y, -cam->getPosition().z);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200.0, -20.00, 0.0);
	glTexCoord2f(0.0, 200.0); glVertex3f(200.0, -200.0, 0.0);
	glTexCoord2f(200.0, 200.0); glVertex3f(200.0, 200.0, 0.0);
	glTexCoord2f(200.0, 0.0); glVertex3f(200.0, -200.0, 0.0);
	glEnd();

		
	//Cube c1 = Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0, 3, -1)), 0.1);
	//c1.render();

	//Sphere s = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 1)), 0.5);
	//s.render();

	//Cylinder cy = Cylinder(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1)), 0.5);
	//cy.render();

	//Cone co = Cone(glm::translate(glm::mat4(1.0f), glm::vec3(-1, 0, 1)), 0.5);
	//co.render();


	glFlush();
}
void init()
{
	glViewport(0, 0, (GLsizei) windowWidth, (GLsizei) windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat aspectRatio = (windowWidth > windowHeight) ? float(windowWidth) / float(windowHeight) : float(windowHeight) / float(windowWidth);
	GLfloat fH = tan(float(fieldOfView / 360.0f * 3.14159f)) * near;
	GLfloat fW = fH * aspectRatio;
	glFrustum(-fW, fW, -fH, fH, near, far);
	


	// Creatint texture
	GLfloat textureData[] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f
	};


	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, textureData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myIdleFunc()
{
	//rotation_angle += 0.01;
	x += 0.0001;
	y -= 0.0001;
	move += 0.001;
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	cam->move(deltaTime / 1000.0f);
	glutPostRedisplay();
}
*/



// ------------------------------------------ Constants & Variables -------------------------------------

#define TEXTURE_FILE "wall.png"
#define SKY_FILE "sky.png"
#define FLOOR_FILE "floor.png"
#define DWALL_FILE "dwall.png"
#define PAXER_FILE "axe2.png"
#define SPACEBAR 32

int maze_struct[14][14] = { {1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 0, 0 },
						   { 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
						   { 1, 2, 1, 0, 1, 1, 0, 1, 1, 1, 2, 1, 0, 0 },
						   { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
						   { 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0 },
						   { 1, 1, 0, 0, 0, 0, 0, 0, 1, 3, 1, 1, 0, 0 },
						   { 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 2, 1, 0, 0 },
						   { 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
						   { 1, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0 },
						   { 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0 },
						   { 1, 2, 1, 0, 2, 1, 0, 0, 0, 1, 0, 1, 0, 0 },
						   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0 },
						   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 1, 0, 0 },
						   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 } };

//Logic constants for map contents
const GLint FINISH = 4;
const GLint DWALL = 3;
const GLint OBJECT = 2;
const GLint WALL = 1;
const GLint PATH = 0;

const GLint TEXTURE_SIZE = 512;
const GLint MAX_APPERROR = 64;
const GLint BMP_HEADER_SIZE = 54; //Assumed 24-bit depth

//Project vars
const GLint WINDOW_MARGIN = 100;
const GLint WINDOW_STARTX = 20;
const GLint WINDOW_STARTY = 20;
const GLint ESCAPE = 27; /* ASCII code for the escape key. */

//Cam vars + Location vars
const GLfloat CAMERA_SINK = 0.005f;
const GLfloat VIEW_FIELD = 45.0f;
const GLfloat NEAR_Z = 0.1f;
const GLfloat FAR_Z = 1000.0f;
const GLfloat START_CAMERA_Y = 7.0f;
const GLfloat START_X_AT = -10.0f;
const GLfloat START_Y_AT = 0.0f;
const GLfloat START_ROT = 270.0f;

//Movement vars + Collision vars
const GLint CONTROLLER_PLAY = 250;
const GLfloat ROTATE_MOUSE_SENSE = 0.00004f;
const GLfloat ROTATE_KEY_SENSE = 0.08f;
const GLfloat WALK_MOUSE_SENSE = 0.000125f;
const GLfloat WALK_KEY_SENSE = 0.125f;
const GLfloat WALK_MOUSE_REVERSE_SENSE = 0.00004f; //Slower when backpedaling
const GLfloat WALK_KEY_REVERSE_SENSE = 0.04f;
const GLfloat BOUNCEBACK = 5.0f; //1.0f means none (just reverse collision)
const GLfloat COLLIDE_MARGIN = 0.15625;  //To keep from looking inside the cubes

//Sky Vars
const GLfloat SKY_DISTANCE = 250.0f;
const GLfloat SKY_SCALE = 6.0f;

//Maze Vars
const GLint XSIZE = 14; //Size of maze (in cubes)
const GLint ZSIZE = 14; //Size of maze (in cubes)
const GLfloat MAZE_EXTREME_LEFT = 3.0f;
const GLfloat MAZE_EXTREME_TOP = -19.0f;
const GLfloat HALF_CUBE = 1.25f;
const GLfloat FULL_CUBE = HALF_CUBE + HALF_CUBE;
const GLfloat LEFTMOST_CUBE_CENTER = MAZE_EXTREME_LEFT + HALF_CUBE;

// File-level variables... these are all position-state / input state variables. OpenGL 
//  callbacks with defined signatures must edit these variables, so there's no easy 
//  alternative to giving them file-level scope.
static GLfloat x_at = START_X_AT;
static GLfloat y_at = START_Y_AT;
static GLfloat rot = START_ROT;
static GLint xin = 0, yin = 0;

static GLuint meshWall; /*Texture for the cube*/
static GLuint skyHaze; /*Texture for the sky*/
static GLuint swTex[5];
GLint width, height; //Dimensions for the loading image
unsigned char* image1;
unsigned char* image2;

//Game info
int numAxes = 0;
int numDWALL = 5;
bool brokeW = false;
bool finishM = false;

//---------------------------------------------- Functions -----------------------------------------------

GLint windowwidth()
{
	static int ret = 0;
	if (!ret)ret = glutGet(GLUT_SCREEN_WIDTH) - WINDOW_MARGIN;
	return ret;
}
GLint windowheight()
{
	static int ret = 0;
	if (!ret)ret = glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_MARGIN;
	return ret;
}

void output(int x, int y, float r, float g, float b, void* font, const char *string)
{
	glColor3f(r, g, b);
	glRasterPos3f(x, 0, y);
	int len = 5, i;
	//len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

//Loads a texture and returns its integer OpenGL handle
GLuint maketex(const char* tfile) //returns tex. no.
{
	GLuint itex;
	GLint width, height; //Dimensions for the loading image
	unsigned char* image = SOIL_load_image(tfile, &width, &height, 0, SOIL_LOAD_RGB);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Now, we need to create pointers to our textures in the memory:
	glGenTextures(1, &itex); //Creates two pointers for the two textures, namely texName[0]

	glBindTexture(GL_TEXTURE_2D, itex); //Set the textName[0] to be the active texture
											  //Set texName[0] to point to the array built before. Note: If you do not set the parameters properly, you will get weird or will not get texture at all.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//Below, we set some parameters required for the texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return itex;
}

//"init" function
void initgl(GLint width, GLint height)
{
	glClearColor(0.1f, 0.1f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(VIEW_FIELD, (GLfloat)width / (GLfloat)height, NEAR_Z, FAR_Z);
	glMatrixMode(GL_MODELVIEW);

	//meshWall = maketex(TEXTURE_FILE);
	//skyHaze = maketex(SKY_FILE);
	unsigned char* image1 = SOIL_load_image(TEXTURE_FILE, &width, &height, 0, SOIL_LOAD_RGB);
	unsigned char* image2 = SOIL_load_image(SKY_FILE, &width, &height, 0, SOIL_LOAD_RGB);
	unsigned char* image3 = SOIL_load_image(PAXER_FILE, &width, &height, 0, SOIL_LOAD_RGB);
	unsigned char* image4 = SOIL_load_image(DWALL_FILE, &width, &height, 0, SOIL_LOAD_RGB);
	//unsigned char* image5 = SOIL_load_image(PAXE_FILE, &width, &height, 0, SOIL_LOAD_RGB);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Now, we need to create pointers to our textures in the memory:
	glGenTextures(4, swTex); //Creates two pointers for the two textures, namely texName[0]

	glBindTexture(GL_TEXTURE_2D, swTex[0]); 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, swTex[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, swTex[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image3);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, swTex[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image4);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//glBindTexture(GL_TEXTURE_2D, swTex[4]);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image5);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

//Applies texture to sky
void sky(GLuint haze)
{ //Modeled after cube front
	glBindTexture(GL_TEXTURE_2D, haze);
	glBegin(GL_QUADS);
		glTexCoord2d(1.0, 1.0);
		glVertex3f((windowwidth() / SKY_SCALE), (windowheight() / SKY_SCALE), -SKY_DISTANCE);
		glTexCoord2d(0.0, 1.0);
		glVertex3f(-(windowwidth() / SKY_SCALE), (windowheight() / SKY_SCALE), -SKY_DISTANCE);
		glTexCoord2d(0.0, 0.0);
		glVertex3f(-(windowwidth() / SKY_SCALE), -(windowheight() / SKY_SCALE), -SKY_DISTANCE);
		glTexCoord2d(1.0, 0.0);
		glVertex3f((windowwidth() / SKY_SCALE), -(windowheight() / SKY_SCALE), -SKY_DISTANCE);
	glEnd();
}

void cube(GLfloat x, GLfloat y, GLfloat z) //Draws a cube centered at (x,y,z)
{
	// Top of cube
	glTexCoord2d(1.0, 1.0);
	glVertex3f(x + HALF_CUBE, HALF_CUBE, z - HALF_CUBE); // Top Right Of The Quad (Top)
	glTexCoord2d(0.0, 1.0);
	glVertex3f(x - HALF_CUBE, HALF_CUBE, z - HALF_CUBE); // Top Left Of The Quad (Top)
	glTexCoord2d(0.0, 0.0);
	glVertex3f(x - HALF_CUBE, HALF_CUBE, z + HALF_CUBE); // Bottom Left Of The Quad (Top)
	glTexCoord2d(1.0, 0.0);
	glVertex3f(x + HALF_CUBE, HALF_CUBE, z + HALF_CUBE); // Bottom Right Of The Quad (Top)

														 // Bottom
	glTexCoord2d(1.0, 1.0);
	glVertex3f(x + HALF_CUBE, -HALF_CUBE, z + HALF_CUBE); // Top Right Of The Quad (Bottom)
	glTexCoord2d(0.0, 1.0);
	glVertex3f(x - HALF_CUBE, -HALF_CUBE, z + HALF_CUBE); // Top Left Of The Quad (Bottom)
	glTexCoord2d(0.0, 0.0);
	glVertex3f(x - HALF_CUBE, -HALF_CUBE, z - HALF_CUBE); // Bottom Left Of The Quad (Bottom)
	glTexCoord2d(1.0, 0.0);
	glVertex3f(x + HALF_CUBE, -HALF_CUBE, z - HALF_CUBE); // Bottom Right Of The Quad (Bottom)

														  // Front
	glTexCoord2d(1.0, 1.0);
	glVertex3f(x + HALF_CUBE, HALF_CUBE, z + HALF_CUBE); // Top Right Of The Quad (Front)
	glTexCoord2d(0.0, 1.0);
	glVertex3f(x - HALF_CUBE, HALF_CUBE, z + HALF_CUBE); // Top Left Of The Quad (Front)
	glTexCoord2d(0.0, 0.0);
	glVertex3f(x - HALF_CUBE, -HALF_CUBE, z + HALF_CUBE); // Bottom Left Of The Quad (Front)
	glTexCoord2d(1.0, 0.0);
	glVertex3f(x + HALF_CUBE, -HALF_CUBE, z + HALF_CUBE); // Bottom Right Of The Quad (Front)

														  // Back
	glTexCoord2d(1.0, 1.0);
	glVertex3f(x - HALF_CUBE, HALF_CUBE, z - HALF_CUBE); // Top Right Of The Quad (Back)
	glTexCoord2d(0.0, 1.0);
	glVertex3f(x + HALF_CUBE, HALF_CUBE, z - HALF_CUBE); // Top Left Of The Quad (Back)
	glTexCoord2d(0.0, 0.0);
	glVertex3f(x + HALF_CUBE, -HALF_CUBE, z - HALF_CUBE); // Bottom Left Of The Quad (Back)
	glTexCoord2d(1.0, 0.0);
	glVertex3f(x - HALF_CUBE, -HALF_CUBE, z - HALF_CUBE); // Bottom Right Of The Quad (Back)

														  // left of cube
	glTexCoord2d(1.0, 1.0);
	glVertex3f(x - HALF_CUBE, HALF_CUBE, z + HALF_CUBE); // Top Right Of The Quad (Left)
	glTexCoord2d(0.0, 1.0);
	glVertex3f(x - HALF_CUBE, HALF_CUBE, z - HALF_CUBE); // Top Left Of The Quad (Left)
	glTexCoord2d(0.0, 0.0);
	glVertex3f(x - HALF_CUBE, -HALF_CUBE, z - HALF_CUBE); // Bottom Left Of The Quad (Left)
	glTexCoord2d(1.0, 0.0);
	glVertex3f(x - HALF_CUBE, -HALF_CUBE, z + HALF_CUBE); // Bottom Right Of The Quad (Left)

														  // Right of cube
	glTexCoord2d(1.0, 1.0);
	glVertex3f(x + HALF_CUBE, HALF_CUBE, z - HALF_CUBE); // Top Right Of The Quad (Right)
	glTexCoord2d(0.0, 1.0);
	glVertex3f(x + HALF_CUBE, HALF_CUBE, z + HALF_CUBE); // Top Left Of The Quad (Right)
	glTexCoord2d(0.0, 0.0);
	glVertex3f(x + HALF_CUBE, -HALF_CUBE, z + HALF_CUBE); // Bottom Left Of The Quad (Right)
	glTexCoord2d(1.0, 0.0);
	glVertex3f(x + HALF_CUBE, -HALF_CUBE, z - HALF_CUBE); // Bottom Right Of The Quad (Right)
}
void sCube(GLfloat x, GLfloat y, GLfloat z, GLfloat scale) //Draws a cube centered at (x,y,z)
{
	// Top of cube
	glTexCoord2d(1.0, 1.0);
	glVertex3f((x + HALF_CUBE)*scale, (HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Top Right Of The Quad (Top)
	glTexCoord2d(0.0, 1.0);
	glVertex3f((x - HALF_CUBE)*scale, (HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Top Left Of The Quad (Top)
	glTexCoord2d(0.0, 0.0);
	glVertex3f((x - HALF_CUBE)*scale, (HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Bottom Left Of The Quad (Top)
	glTexCoord2d(1.0, 0.0);
	glVertex3f((x + HALF_CUBE)*scale, (HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Bottom Right Of The Quad (Top)

																				   // Bottom
	glTexCoord2d(1.0, 1.0);
	glVertex3f((x + HALF_CUBE)*scale, -(HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Top Right Of The Quad (Bottom)
	glTexCoord2d(0.0, 1.0);
	glVertex3f((x - HALF_CUBE)*scale, -(HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Top Left Of The Quad (Bottom)
	glTexCoord2d(0.0, 0.0);
	glVertex3f((x - HALF_CUBE)*scale, -(HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Bottom Left Of The Quad (Bottom)
	glTexCoord2d(1.0, 0.0);
	glVertex3f((x + HALF_CUBE)*scale, -(HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Bottom Right Of The Quad (Bottom)

																					// Front
	glTexCoord2d(1.0, 1.0);
	glVertex3f((x + HALF_CUBE)*scale, (HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Top Right Of The Quad (Front)
	glTexCoord2d(0.0, 1.0);
	glVertex3f((x - HALF_CUBE)*scale, (HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Top Left Of The Quad (Front)
	glTexCoord2d(0.0, 0.0);
	glVertex3f((x - HALF_CUBE)*scale, -(HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Bottom Left Of The Quad (Front)
	glTexCoord2d(1.0, 0.0);
	glVertex3f((x + HALF_CUBE)*scale, -(HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Bottom Right Of The Quad (Front)

																					// Back
	glTexCoord2d(1.0, 1.0);
	glVertex3f((x - HALF_CUBE)*scale, (HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Top Right Of The Quad (Back)
	glTexCoord2d(0.0, 1.0);
	glVertex3f((x + HALF_CUBE)*scale, (HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Top Left Of The Quad (Back)
	glTexCoord2d(0.0, 0.0);
	glVertex3f((x + HALF_CUBE)*scale, -(HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Bottom Left Of The Quad (Back)
	glTexCoord2d(1.0, 0.0);
	glVertex3f((x - HALF_CUBE)*scale, -(HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Bottom Right Of The Quad (Back)

																					// left of cube
	glTexCoord2d(1.0, 1.0);
	glVertex3f((x - HALF_CUBE)*scale, (HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Top Right Of The Quad (Left)
	glTexCoord2d(0.0, 1.0);
	glVertex3f((x - HALF_CUBE)*scale, (HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Top Left Of The Quad (Left)
	glTexCoord2d(0.0, 0.0);
	glVertex3f((x - HALF_CUBE)*scale, -(HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Bottom Left Of The Quad (Left)
	glTexCoord2d(1.0, 0.0);
	glVertex3f((x - HALF_CUBE)*scale, -(HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Bottom Right Of The Quad (Left)

																					// Right of cube
	glTexCoord2d(1.0, 1.0);
	glVertex3f((x + HALF_CUBE)*scale, (HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Top Right Of The Quad (Right)
	glTexCoord2d(0.0, 1.0);
	glVertex3f((x + HALF_CUBE)*scale, (HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Top Left Of The Quad (Right)
	glTexCoord2d(0.0, 0.0);
	glVertex3f((x + HALF_CUBE)*scale, -(HALF_CUBE * scale), (z + HALF_CUBE)*scale); // Bottom Left Of The Quad (Right)
	glTexCoord2d(1.0, 0.0);
	glVertex3f((x + HALF_CUBE)*scale, -(HALF_CUBE * scale), (z - HALF_CUBE)*scale); // Bottom Right Of The Quad (Right)
}

void print_maze(GLuint wtex, GLuint dwtex, GLuint otex ) //Renders the necessary OpenGL cubes
{
	int x, z;
	/*
	//Printing first wall
	for (x = 0; x<XSIZE; ++x) //Print a border
	{
		cube(MAZE_EXTREME_LEFT + HALF_CUBE + ((GLfloat)x*FULL_CUBE), 0.0, MAZE_EXTREME_TOP + HALF_CUBE);

		cube(MAZE_EXTREME_LEFT + HALF_CUBE + ((GLfloat)x*FULL_CUBE),
			0.0,
			MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + (YSIZE*(FULL_CUBE)));
	}*/

	//Printing the walls
	for (z = 0; z<ZSIZE; z++)
	{
		for (x = 0; x<XSIZE; x++)
		{
			if ( maze_struct[x][z] == WALL ) //Printing based on maze design
			{
				cube(LEFTMOST_CUBE_CENTER + ((GLfloat)x*FULL_CUBE),
					0.0,
					MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z*FULL_CUBE));

			} else if (maze_struct[x][z] == DWALL) //Printing based on maze design
			{
				cube(LEFTMOST_CUBE_CENTER + ((GLfloat)x*FULL_CUBE),
					0.0,
					MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z*FULL_CUBE));

			} //else if (maze_struct[x][z] == OBJECT) //Printing based on maze design
			//{
				//sCube(LEFTMOST_CUBE_CENTER + ((GLfloat)x*FULL_CUBE),
					//0.0,
					//MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z*FULL_CUBE), 1/5);
			//}

		}
	}
	
}

bool collide() //Is player in a state of collision?
{
	int x, y;

	//Outside Walls...
	if ( (x_at >= MAZE_EXTREME_LEFT - COLLIDE_MARGIN) && (x_at <= MAZE_EXTREME_LEFT + XSIZE*FULL_CUBE + COLLIDE_MARGIN) )
	{
		if ( (y_at <= (MAZE_EXTREME_TOP + FULL_CUBE) + COLLIDE_MARGIN) && (y_at >= MAZE_EXTREME_TOP - COLLIDE_MARGIN) )
		{
			return 1;
		}

		if (y_at <= (MAZE_EXTREME_TOP + FULL_CUBE) + FULL_CUBE + (ZSIZE*FULL_CUBE) + COLLIDE_MARGIN &&
			y_at >= MAZE_EXTREME_TOP + FULL_CUBE + (ZSIZE*FULL_CUBE) - COLLIDE_MARGIN)
		{
			return 1;
		}
	}

	//Inner Maze
	for (y = 0; y<ZSIZE; ++y)
	{
		for (x = 0; x<XSIZE; ++x)
		{
			if ( maze_struct[x][y] == WALL || maze_struct[x][y] == DWALL)
			{
				if ( (x_at >= MAZE_EXTREME_LEFT + x*FULL_CUBE - COLLIDE_MARGIN)             &&
					 (x_at <= MAZE_EXTREME_LEFT + FULL_CUBE + x*FULL_CUBE + COLLIDE_MARGIN) &&
					 (y_at >= MAZE_EXTREME_TOP + (y + 1)*FULL_CUBE - COLLIDE_MARGIN)        &&
					 (y_at <= MAZE_EXTREME_TOP + (y + 2)*FULL_CUBE + COLLIDE_MARGIN) )
				{
					return 1;
				}
			}

			if (maze_struct[x][y] == DWALL)
			{
				if ((x_at >= MAZE_EXTREME_LEFT + x*FULL_CUBE - 5) &&
					(x_at <= MAZE_EXTREME_LEFT + FULL_CUBE + x*FULL_CUBE + 5) &&
					(y_at >= MAZE_EXTREME_TOP + y*FULL_CUBE - COLLIDE_MARGIN -8) &&
					(y_at <= MAZE_EXTREME_TOP + y*FULL_CUBE + COLLIDE_MARGIN +8 ))
				{
					//Print to screen 
					// Press key, get rid of wall
					if (brokeW) {
						maze_struct[x][y] = 0;
						brokeW = false;
					}
					
				}
			}

			if (maze_struct[x][y] == FINISH)
			{
				if ((x_at >= MAZE_EXTREME_LEFT + x*FULL_CUBE - 4) &&
					(x_at <= MAZE_EXTREME_LEFT + FULL_CUBE + x*FULL_CUBE + 4) &&
					(y_at >= MAZE_EXTREME_TOP + y*FULL_CUBE - COLLIDE_MARGIN - 4) &&
					(y_at <= MAZE_EXTREME_TOP + y*FULL_CUBE + COLLIDE_MARGIN + 4))
				{
					//Print to screen 
					// Press key, get rid of wall
					//if (brokeW) {
					//	maze_struct[x][y] = 0;
					//	brokeW = false;
					//}
					finishM = true;

				}
			}

		}
	}
	return 0;
}

//Monitor movement
void move(GLfloat amt) //Move, incorporating collision and bounceback
{
	x_at += cos(rot)*amt;
	y_at += sin(rot)*amt;
	if (collide()) //Don't let player walk through walls
	{
		x_at -= BOUNCEBACK*cos(rot)*amt;
		y_at -= BOUNCEBACK*sin(rot)*amt;
	}
	if (collide()) //Bounced into another wall... just reverse original move
	{
		x_at += BOUNCEBACK*cos(rot)*amt;
		y_at += BOUNCEBACK*sin(rot)*amt;
		x_at -= cos(rot)*amt;
		y_at -= sin(rot)*amt;
	}

	/*
	std::string s = numDWALL + " / 5";
	const char* wallsLeft = nullptr;
	char* temp = nullptr;
	//int w = glutBitmapLength(GLUT_BITMAP_8_BY_13, s);

	for (int i = 0; i < s.length(); i++) {
		temp[i] = s[i];
	}
	wallsLeft = temp;
	output(x_at, y_at, 1.0, 0.0, 0.0, GLUT_BITMAP_8_BY_13, wallsLeft);
	*/
}

void arrows(GLint key, GLint x, GLint y)
{
	if (key == GLUT_KEY_UP)
		move(WALK_KEY_SENSE);
	if (key == GLUT_KEY_DOWN)
		move(-WALK_KEY_REVERSE_SENSE);
	if (key == GLUT_KEY_RIGHT)
		rot += ROTATE_KEY_SENSE;
	if (key == GLUT_KEY_LEFT)
		rot -= ROTATE_KEY_SENSE;
	if (key == SPACEBAR) brokeW = true;
}


void drawscene()
{
	if (finishM)
		exit(0);

	glLoadIdentity(); // Loads everything???????

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	static GLfloat camera_y = START_CAMERA_Y;
	static bool init = 0;
	
	//std::string s = numDWALL + " / 5";
	//unsigned char* wallsLeft = nullptr;
	//int w = glutBitmapLength(GLUT_BITMAP_8_BY_13, s);

	//for (int i = 0; i < s.length(); i++) {
	//	wallsLeft[i] = s[i];
	//}

	//wallsLeft[s.length()] = '/0';
	//glRasterPos2f(1.0, 1.0);
	
	//for (int i = 0; i < s.length(); i++) {
	//	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, wallsLeft[i]);
	//}

	
	//static GLuint meshWall; /*Texture for the cube*/
	//static GLuint skyHaze; /*Texture for the sky*/

	//if (!init)
	//{
		//init = 1;
		//meshWall = maketex(TEXTURE_FILE);
		//skyHaze = maketex(SKY_FILE);
	//}

	//In case of controller?
	/*if (camera_y <= 0.0f && xin && yin)
	{
		if (yin<CONTROLLER_PLAY)
			//move((yin - windowheight() / 2.0f)*-WALK_MOUSE_SENSE);

		if (yin>(windowheight() - CONTROLLER_PLAY))
			//move(((windowheight() / 2.0f) - yin)*WALK_MOUSE_REVERSE_SENSE);
		
		if (xin<CONTROLLER_PLAY || xin>(windowwidth() - CONTROLLER_PLAY))
			rot += (xin - (windowwidth() / 2.0f))*ROTATE_MOUSE_SENSE;
	}*/

	
	
	sky(swTex[1]); //Draw sky

	//glBindTexture(GL_TEXTURE_2D, swTex[2]);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0, 0.0); glVertex3f(MAZE_EXTREME_LEFT, 0.0, MAZE_EXTREME_TOP);
	//glTexCoord2f(0.0, 200.0); glVertex3f(MAZE_EXTREME_LEFT, 0.0, (MAZE_EXTREME_TOP + FULL_CUBE) * 12);
	//glTexCoord2f(200.0, 200.0); glVertex3f((MAZE_EXTREME_LEFT + FULL_CUBE) * 12, 0.0, (MAZE_EXTREME_TOP + FULL_CUBE) * 12);
	//glTexCoord2f(200.0, 0.0); glVertex3f((MAZE_EXTREME_LEFT + FULL_CUBE) * 12, 0.0, MAZE_EXTREME_TOP);
	//glEnd();

	gluLookAt(x_at, camera_y, y_at, x_at + cos(rot), camera_y, y_at + sin(rot), 0.0, 1.0, 0.0);
	if (camera_y>0.0) camera_y -= CAMERA_SINK; //The user falls into the maze

	//glBindTexture(GL_TEXTURE_2D, swTex[0]);
	//glBegin(GL_QUADS); // Draw the cube (6 faces)
		//print_maze(swTex[0], swTex[3], swTex[4]);		   //Printing the walls
	int x_, z_;
	for (z_ = 0; z_<ZSIZE; z_++)
	{
		for (x_ = 0; x_<XSIZE; x_++)
		{
			if (maze_struct[x_][z_] == WALL) //Printing based on maze design
			{
				glBindTexture(GL_TEXTURE_2D, swTex[0]);
				glBegin(GL_QUADS);
					cube(LEFTMOST_CUBE_CENTER + ((GLfloat)x_*FULL_CUBE),
						0.0,
						MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z_*FULL_CUBE));
				glEnd();
			}
			else if (maze_struct[x_][z_] == DWALL) //Printing based on maze design
			{
				glBindTexture(GL_TEXTURE_2D, swTex[3]);
				glBegin(GL_QUADS);
				cube(LEFTMOST_CUBE_CENTER + ((GLfloat)x_*FULL_CUBE),
					0.0,
					MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z_*FULL_CUBE));
				glEnd();
			} else if (maze_struct[x_][z_] == OBJECT) //Printing based on maze design
			  {
				
				glBindTexture(GL_TEXTURE_2D, swTex[2]);
				glPushMatrix();
				glBegin(GL_QUADS);
				  sCube(LEFTMOST_CUBE_CENTER + ((GLfloat)x_*FULL_CUBE),
				  0.0,
				  MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z_*FULL_CUBE), 1/2);
				glEnd();
				glPopMatrix();
			}
			/*else if (maze_struct[x_][z_] == FINISH) //Printing based on maze design
			{

				glBindTexture(GL_TEXTURE_2D, swTex[3]);
				glPushMatrix();
				glBegin(GL_QUADS);
				cube(LEFTMOST_CUBE_CENTER + ((GLfloat)x_*FULL_CUBE),
					0.0,
					MAZE_EXTREME_TOP + HALF_CUBE + FULL_CUBE + ((GLfloat)z_*FULL_CUBE));
				glEnd();
				glPopMatrix();
			}*/
		}
	}
		
	//glEnd(); // Done Drawing The Cube

	//glutSwapBuffers();
	glFlush();
}

//Close program if window is resized
void resizer(GLint width, GLint height)
{
	if (width != windowwidth() || height != windowheight()) exit(0);
}

//Exit program if intended
void keypress(unsigned char key, GLint x, GLint y)
{
	if (key == ESCAPE)exit(0);
	if (key == 'b') brokeW = true;
}

// ---------------------------------------------- Main Function -------------------------------------------

int main(int argc, char** argv)
{
	/*
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Maze Gayme");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdleFunc);

	glutKeyboardFunc(handleKeyPresses);
	glutKeyboardUpFunc(handleKeyReleased);
	glutMouseFunc(handleMouseMove);

	cam = new Camera(windowWidth, windowHeight);
	init();
	glutMainLoop();
	return 0;
	*/

	/* The number of our GLUT window */
	GLuint window;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glDisable(GLUT_ALPHA);
	glutInitWindowSize(windowwidth(), windowheight());
	glutInitWindowPosition(WINDOW_STARTX, WINDOW_STARTY);

	window = glutCreateWindow("Mez gayme");
	initgl(windowwidth(), windowheight());
	
	glutDisplayFunc(drawscene);
	glutIdleFunc(drawscene);
	glutReshapeFunc(&resizer);
	glutSpecialFunc(&arrows); //"Special" key presses
	glutKeyboardFunc(&keypress); //"Special" key presses
	//glutPassiveMotionFunc(&mouse);
	
	//glewInit();
	//srand(time(0));

	//make_solution();
	//obfuscate_maze();
	//if (!finishM)
	//	exit(0);

	glutMainLoop();

	
	return 0;

}