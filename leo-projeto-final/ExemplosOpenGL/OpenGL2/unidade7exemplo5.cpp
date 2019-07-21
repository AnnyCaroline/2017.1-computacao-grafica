// Unidade 7 - Exemplo 5: Textura esfera

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"
using namespace std;

// Funções callback
void desenharCenaU7E5();
void alterarTamanhoJanelaU7E5(int x, int y);
GLuint loadTextureFromFileU7E5(const char *nomeArquivo);
void lerTecladoU7E5(unsigned char key, int x, int y);
void iniciarRenderizacaoU7E5();
void atualizarU7E5(int value);

// Variáveis globais
const char* nomeArquivo = "./textures/earthmap1k.bmp"; //image file with the texture
char view = 's';
GLuint _textureId; //The id of the texture
GLUquadric *quad;
float rotationAngle;

void mainU7E5(void) {

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	glutCreateWindow("Textured Earth");
	iniciarRenderizacaoU7E5();
	glutTimerFunc(25, atualizarU7E5, 0);
	glutDisplayFunc(desenharCenaU7E5);
	glutKeyboardFunc(lerTecladoU7E5);
	glutReshapeFunc(alterarTamanhoJanelaU7E5);
}


void desenharCenaU7E5() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	switch (view) {
	case 't': //Top view
		gluLookAt(0.0f, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f);
		break;
	case 's': //Side view
		gluLookAt(20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		break;
	case 'b': //Bottom view
		gluLookAt(0.0f, 0.0f, -20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		break;
	}
	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(quad, 1);
	gluSphere(quad, 4, 40, 40);
	glutSwapBuffers();
}

// callback para redimensionar janela glut
void alterarTamanhoJanelaU7E5(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

// carrega textura de arquivo
GLuint loadTextureFromFileU7E5(const char *nomeArquivo) {
	GLuint textureId;
	RgbImage theTexMap(nomeArquivo); //Image with texture
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Texture to be edited
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D, //Always GL_TEXTURE_2D
		0, //0 for now
		GL_RGB, //Format OpenGL uses for image
		theTexMap.GetNumCols(), //Width
		theTexMap.GetNumRows(), //Height
		0, //The border of the image
		GL_RGB, //GL_RGB: pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE:pixels are stored as
							//unsigned numbers
		theTexMap.ImageData()); //The actual pixel data
	return textureId; //Returns the id of the texture
}

// callback de teclado
void lerTecladoU7E5(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0); break;
	case 't': //Top view
		view = key; glutPostRedisplay(); break;
	case 's': //Side view
		view = key; glutPostRedisplay(); break;
	case 'b': //Bottom view
		view = key; glutPostRedisplay(); break;
	}
}

void iniciarRenderizacaoU7E5() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	quad = gluNewQuadric();
	_textureId = loadTextureFromFileU7E5(nomeArquivo);
}

void atualizarU7E5(int value) {
	rotationAngle += 1.0f;
	if (rotationAngle>360.f)
		rotationAngle -= 360;
	glutPostRedisplay();
	glutTimerFunc(25, atualizarU7E5, 0);
}