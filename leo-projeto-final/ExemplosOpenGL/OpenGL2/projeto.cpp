// Unidade 7 - Exemplo 1: Ponto de Vista

#include <stdio.h>
#include <math.h>
#include <gl/glut.h>
#include <iostream>
#include "RgbImage.h"
using namespace std;

#define ESC_KEY 27

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WINDOW_TITLE "Robotic Explorer"

#define BACKGROUND_COLOR_RGBA 0.8, 1.0, 1.0, 0.0
#define PLATFORM_COLOR_RGB 0.3, 0.3, 0.3
#define ROBOT_COLOR_RGB 0.8, 0.8, 0.8

#define LIGHT_POSITION 3.0, 3.0, 3.0, 0.0

#define MAX_EYE_HEIGHT 20.0
#define MIN_EYE_HEIGHT 2.0

#define FRUSTUM_SPACE -3.0, 3.0, -3.0, 3.0, 3.0, 60.0
#define LOOK_AT_UP_XYZ 0.0, 1.0, 0.0

#define WOOD_TEXTURE_FILE "./textures/wood.bmp"

// Funções de inicialização
void createWindow();
void initLighting();
//void initTextures();
void registerCallbacks();

// Funções callback
void draw();
void resizeWindow(GLsizei w, GLsizei h);
void readKeyboard(unsigned char key, int x, int y);
void readMouse(int button, int state, int x, int y);

// Funções de desenho
void prepareProjection();
//void loadTextureFromFile(const char *filename);
void drawPlatform();
void drawRobot();

// Variáveis globais
//GLuint textures[1]; // id da textura
GLdouble alpha = 0.0, eyeHeight = 5.0, radius = 10.0; // TODO TESTAR VALORES

void mainProjeto(void) {
	createWindow();
	initLighting();
	//initTextures();
	registerCallbacks();
}

void createWindow() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);
}

void initLighting() {
	GLfloat lightPosition[] = { LIGHT_POSITION };
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(BACKGROUND_COLOR_RGBA);
}

void registerCallbacks() {
	glutDisplayFunc(draw);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(readKeyboard);
	glutMouseFunc(readMouse);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	prepareProjection();

	drawPlatform();
	drawRobot();

	glutSwapBuffers();
}

void prepareProjection() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(FRUSTUM_SPACE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		sin(alpha) * radius, eyeHeight, cos(alpha) * radius,
		0.0, 0.0, 0.0,
		LOOK_AT_UP_XYZ);
}


void drawPlatform() {
	glPushMatrix();
		glColor3f(PLATFORM_COLOR_RGB);
		glScalef(20.0, 2.0, 20.0);
		//glBindTexture(GL_TEXTURE_2D, textures[0]); // Necessário gerar cubo manualmente
		glutSolidCube(1.0);
	glPopMatrix();
}

void drawRobot() {}

void resizeWindow(GLsizei w, GLsizei h) {
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void readKeyboard(unsigned char key, int x, int y) {
	cout << key;
	/* if (key == ESC_KEY) {
		exit(0);
	} else if (isCameraMovementKey(key)) {
		handleCameraMovement(key);
	} else if (isRobotMovementKey(key)) {
		handleRobotMovement(key);
	} */

}

void readMouse(int button, int state, int x, int y) {

}
/* void initTextures() {
	glEnable(GL_TEXTURE_2D);
	loadTextureFromFile(WOOD_TEXTURE_FILE);
} */

/* void loadTextureFromFile(const char *filename) {
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	RgbImage theTexMap(filename);
	glGenTextures(1, &textures[0]); // Cria a textura
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, //Sempre GL_TEXTURE_2D
		0, //Nível de detalhe da textura (0)
		3, //Numero de componentes de cor
		theTexMap.GetNumCols(), //Largura
		theTexMap.GetNumRows(), //Altura
		0, //Bordas (deve ser 0)
		GL_RGB, //Formato interno: RGB
		GL_UNSIGNED_BYTE, //Pixels armazenados como unsigned
		theTexMap.ImageData()); //A imagem/pixels da textura
} */