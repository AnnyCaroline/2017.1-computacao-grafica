// PrimeiroPrograma.c - Isabel H. Manssour
// Um programa OpenGL simples que abre uma janela GLUT
// Este código está baseado no Simple.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.
#include <gl/glut.h>
#include "exemplosUnidade6.h"
#include "exemplosUnidade7.h"
#include "projeto.h"


// Programa Principal
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	mainU7E5();
	//mainProjeto();
	glutMainLoop();
	return 0;
}

