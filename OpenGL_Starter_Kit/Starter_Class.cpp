#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Tank.h"
#include "Circle.h"
#include "Camera.h"
#include "Sphere.h"
#include "Cube.h"
#include "Vehicle.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Spaceship.h"


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
			if (rotateS != 0) {
				rotateS = 0;
			}

			transZ += 0.1;



			break;
		case 'f':
			rotateZ = 1;
			if(rotateS == 0)
				rotateS = 90;
				transZ = -transZ;


			transX -= 0.1;
			break;

		case 'g':
			//rotateX = 1;
			if (rotateS == 0) {
				rotateS = 180;
				transZ = -transZ;
			}
			
			
			//rotateY = 1;

			//rotateZ = 1;

			transZ += 0.1;

			break;
		case 'h':
			rotateS = 90;

			rotateY = 1;

			//rotateZ = 1;

			transZ += 0.1;
			
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
		//rotateS = 0;

		break;
	case 'f':
		//rotateX = 0;
		//rotateS = 0;

		break;
	case 'g':
		//rotateZ = 0;

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

	//glDisable(GL_TEXTURE_2D);
	//Sphere sp = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), 0.1);
	//sp.render();s

	//Sphere sp1 = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(0,0.5, 0)), 0.1);
	//sp1.render();

	//Sphere sp2 = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(0.5, 0, 0)), 0.1);
	//sp2.render();w
		
	//Cube c1 = Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0, 3, -1)), 0.1);
	//c1.render();
	
	//Vehicle v1 = Vehicle(glm::translate(glm::mat4(1.0f), glm::vec3(move, 3, 0)), 0.2);
	//v1.render();

	//Sphere s = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 1)), 0.5);
	//s.render();

	//Cylinder cy = Cylinder(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1)), 0.5);
	//cy.render();

	//Cone co = Cone(glm::translate(glm::mat4(1.0f), glm::vec3(-1, 0, 1)), 0.5);
	//co.render();

	Spaceship ship = Spaceship(glm::translate(glm::mat4(1.0f), glm::vec3(transX, transY, transZ)), 0.5);
	glRotatef(rotateS, rotateX, rotateY, rotateZ);
	ship.render();

	glFlush();
}


void createShip() {
	Spaceship ship = Spaceship(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), 0.5);
		glRotatef(rotateS, rotateX, rotateY, rotateZ);
	ship.render();
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First Application");
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
}