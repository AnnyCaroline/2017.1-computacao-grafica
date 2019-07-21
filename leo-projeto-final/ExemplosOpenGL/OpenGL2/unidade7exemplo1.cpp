// Unidade 7 - Exemplo 1: Ponto de Vista

#include <stdio.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;

#define ESC_KEY 27

// Funções callback
void desenharObjetoU7E1(void); // desenha o bule
void resetarGiroObjetoU7E1(void); // rotaciona bule
void iniciarIluminacaoU7E1(void); // define a fonte de luz
void alterarTamanhoJanelaU7E1(int width, int height); // callback de redesenho da
														// janela glut
void desenharU7E1(void); // callback de desenho
void lerTecladoU7E1(unsigned char key, int x, int y); // callback de teclado

// Variáveis globais
GLint Width = 800;
GLint Height = 800;
static GLfloat spin_z = 0.0;
static GLfloat spin_y = 0.0;
char objectId = 'b';


void mainU7E1(void) {

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Bule em 4 vistas");
	iniciarIluminacaoU7E1();

	glutDisplayFunc(desenharU7E1);
	glutReshapeFunc(alterarTamanhoJanelaU7E1);
	glutKeyboardFunc(lerTecladoU7E1);
}

// desenha o objeto
void desenharObjetoU7E1(void) {
	switch (objectId) {
		case 'b':
			glColor3f(1.0, 1.0, 1.0);
			glutSolidTeapot(2.0);
			break;
		case 'd':
			glColor3f(1.0, 1.0, 1.0);
			glutSolidDodecahedron();
			break;
		case 'c':
			glColor3f(1.0, 1.0, 1.0);
			glutSolidCube(2.0);
			break;
		case 'e':
			glColor3f(1.0, 1.0, 1.0);
			glutSolidSphere(2.0, 16.0, 5.0);
			break;
		default:
			return;
	}
}

// rotaciona objeto
void resetarGiroObjetoU7E1(void) {
	if (spin_z > 360.0) {
		spin_z = spin_z - 360.0;
	}
	if (spin_y > 360.0) {
		spin_y = spin_y - 360.0;
	}
	glutPostRedisplay();
}

// callback de redesenho da janela glut
void alterarTamanhoJanelaU7E1(int width, int height) {
	Width = width;
	Height = height;
	//glViewport(0, 0, width, height);
	glutPostRedisplay();
}

// define a fonte de luz (LIGHT0)
void iniciarIluminacaoU7E1(void) {
	GLfloat lightposition[] = { 3.0, -3.0, 3.0, 0.0 };
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 1.0, 1.0, 0.0);
}

// callback de teclado
void lerTecladoU7E1(unsigned char key, int x, int y) {
	cout << key;
	switch (key) {
		case ESC_KEY:
			exit(0);
			break;
		case 'a':
			spin_z -= 2.0; 
			resetarGiroObjetoU7E1();
			break;
		case 's':
			spin_z += 2.0; 
			resetarGiroObjetoU7E1();
			break;
		case 'z':
			spin_y -= 2.0; 
			resetarGiroObjetoU7E1();
			break;
		case 'w':
			spin_y += 2.0;
			resetarGiroObjetoU7E1();
			break;
		case 'o':
			if (objectId == 'b') {
				objectId = 'd';
			}
			else {
				objectId = 'b';
			}
			glutPostRedisplay(); 
			break;
		case 'c':
			objectId = 'c';
			glutPostRedisplay();
			break;
		case 'e':
			objectId = 'e';
			glutPostRedisplay();
			break;
		default:
			return;
	}
}

// callback de desenho
void desenharU7E1(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// viewport topo/esquerda
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	desenharObjetoU7E1();

	// viewport topo/direita
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	desenharObjetoU7E1();

	// viewport baixo/esquerda
	glViewport(0, 0, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	desenharObjetoU7E1();

	// viewport baixo/direita
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2.0, 2.0, -2.0, 2.0, 1.5, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glRotatef(spin_z, 0.0, 0.0, 1.0);
	glRotatef(spin_y, 0.0, 1.0, 0.0);
	desenharObjetoU7E1();

	glutSwapBuffers();
}