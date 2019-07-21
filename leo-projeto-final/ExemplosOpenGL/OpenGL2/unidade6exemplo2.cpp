// Unidade 6 - Exemplo 2: Desenho 2D

#include <gl/glut.h>

// Funções callback
void desenharU6E2(void);
void lerTecladoU6E2(unsigned char key, int x, int y);

void inicializarU6E2(void);


void mainU6E2(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Segundo Programa");
	glutDisplayFunc(desenharU6E2);
	glutKeyboardFunc(lerTecladoU6E2);
	inicializarU6E2();
}

void desenharU6E2(void) {
	//Limpa a janela de visualização com a cor branca
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Define a cor de desenho: vermelho
	glColor3f(1, 0, 0);
	//Desenha um triângulo no centro da janela, colocando uma cor para cada vértice
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glColor3f(0, 1, 0);
		glVertex2f(0.0, 0.5);
		glColor3f(0, 0, 1);
		glVertex2f(0.5, -0.5);
	glEnd();
	//Executa os comandos OpenGL
	glFlush();
}

void lerTecladoU6E2(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
}

void inicializarU6E2(void) {
	// Define a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

