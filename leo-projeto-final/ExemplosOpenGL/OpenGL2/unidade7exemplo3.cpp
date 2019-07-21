// Unidade 7 - Exemplo 3: Normais

#include <stdlib.h>
#include <gl/glut.h>

// Funções callback
void desenharCuboU7E3(void);
void idleFuncU7E3(void);
void lerTecladoU7E3(unsigned char key, int x, int y);
void alterarTamanhoJanelaU7E3(int x, int y);
void iniciarIluminacaoU7E3(void); // define a fonte de luz
void inicializarU7E3(void);


// Variáveis globais
GLfloat xRotated, yRotated, zRotated; //angulos de rotacao
bool normal; //indica se normais estão sendo usadas

void mainU7E3(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(240, 240);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cubo iluminado");
	iniciarIluminacaoU7E3();
	glutDisplayFunc(desenharCuboU7E3);
	glutReshapeFunc(alterarTamanhoJanelaU7E3);
	glutKeyboardFunc(lerTecladoU7E3);
	glutIdleFunc(idleFuncU7E3);
}


void desenharCuboU7E3(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5);
	glRotatef(yRotated, 0, 1, 0);
	glRotatef(zRotated, 0, 0, 1);

	// Desenha um cubo
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS); // Face posterior
	if (normal)
		glNormal3f(0.0, 0.0, 1.0); // Normal da face
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_QUADS); // Face frontal
	if (normal)
		glNormal3f(0.0, 0.0, -1.0); // Normal da face
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS); // Face lateral esquerda
	if (normal)
		glNormal3f(-1.0, 0.0, 0.0); // Normal da face
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBegin(GL_QUADS); // Face lateral direita
	if (normal)
		glNormal3f(1.0, 0.0, 0.0); // Normal da face
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS); // Face superior
	if (normal)
		glNormal3f(0.0, 1.0, 0.0); // Normal da face
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS); // Face inferior
	if (normal)
		glNormal3f(0.0, -1.0, 0.0); // Normal da face
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glutSwapBuffers();
}

void lerTecladoU7E3(unsigned char key, int x, int y) {
	switch (key) {
		case 27: 
			exit(0);
			break;
		case 'n': 
			normal = !normal;
		default: 
			break;
	}
}

// callback idle
void idleFuncU7E3(void) {
	yRotated += 0.01;
	zRotated += 0.01;
	desenharCuboU7E3();
}

// callback de redesenho da janela glut
void alterarTamanhoJanelaU7E3(int x, int y) {
	if (y == 0 || x == 0) return;
	//define projecao
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.5, 1.5, -1.5, 1.5, 3.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	if (x>y) glViewport(0, 0, y, y);
	else glViewport(0, 0, x, x);
}

// define a fonte de luz (LIGHT0)
void iniciarIluminacaoU7E3(void) {
	GLfloat lightposition[] = { 3.0, 3.0, 3.0, 0.0 };
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 0.0, 1.0, 0.0);
}

// Inicializa parâmetros de iluminação
void inicializarU7E3(void) {

}
