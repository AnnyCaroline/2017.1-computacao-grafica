// Unidade 6 - Exemplo 1: Janela Glut

#include <gl/glut.h>

// Funções callback
void desenharU6E1(void);

void inicializarU6E1(void);


void mainU6E1(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(desenharU6E1);
	inicializarU6E1();
}

// Função callback chamada para fazer o desenho
void desenharU6E1(void) {
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//Executa os comandos OpenGL
	glFlush();
}

// Inicializa parâmetros de rendering
void inicializarU6E1(void) {
	// Define a cor de fundo da janela de visualização como azul
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}