// Unidade 6 - Exemplo 4: Interface-Movimento (Não está funcionando)

#include <gl/glut.h>

// Funções callback
void desenharU6E4(void);
void lerMovimentoMouseU6E4(int x, int y);
void lerBotaoMouseU6E4(int button, int state, int x, int y);
void alterarTamanhoJanelaU6E4(GLsizei w, GLsizei h);


// Variáveis globais
float largura, altura; // tamanho da world window e do viewport
float rx, ry; // posição inicial do retângulo vermelho


void mainU6E4(void) {
	largura = 600;
	altura = 600;

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glClearColor(0, 0, 0, 1);
	glutPositionWindow(200, 100);
	glutReshapeWindow(largura, altura);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, largura, 0, altura);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(desenharU6E4);
	glutIdleFunc(desenharU6E4);
	glutMotionFunc(lerMovimentoMouseU6E4);
	glutMouseFunc(lerBotaoMouseU6E4);
	glutReshapeFunc(alterarTamanhoJanelaU6E4);
}

void desenharU6E4(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0); // desenha em amarelo
	glRectf(100, 100, 300, 200); // desenha retângulo amarelo
	glColor3f(1, 0, 0); // desenha em vermelho
	glRectf(rx, ry, 100 + rx, 20 + ry); // desenha retângulo vermelho
	glutSwapBuffers(); // buffer de cor duplo
}

void lerMovimentoMouseU6E4(int x, int y) {
	rx = x; 
	ry = altura - y;
}

void lerBotaoMouseU6E4(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		rx = x; 
		ry = altura - y;
	}
}

void alterarTamanhoJanelaU6E4(GLsizei w, GLsizei h) {
	largura = w;
	altura = h;
	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura); // comando não necessário:
									   // comportamento default

	// Inicializa o sistema de coordenadas do mundo
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Dimensões da World Window (left, right, bottom, top)
	gluOrtho2D(0, largura, 0, altura);
}
