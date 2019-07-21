// Unidade 7 - Exemplo 2: Iluminação

#include <stdlib.h>
#include <gl/glut.h>

// Funções callback
void desenharU7E2(void);
void alterarTamanhoJanelaU7E2(GLsizei w, GLsizei h);
void gerenciarMouseU7E2(int button, int state, int x, int y);
void inicializarU7E2(void);

// Variáveis globais
GLfloat angle, fAspect;

void mainU7E2(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 350);
	glutCreateWindow("Bule Iluminado");
	glutDisplayFunc(desenharU7E2);
	glutReshapeFunc(alterarTamanhoJanelaU7E2);
	glutMouseFunc(gerenciarMouseU7E2);
	inicializarU7E2();
}


// callback de desenho
void desenharU7E2(void) {

	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, fAspect, 0.4, 500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
	// Desenha o teapot com a cor corrente (solid)
	glColor3f(0.6f, 0.4f, 0.1f);
	glutSolidTeapot(50.0f);

	glutSwapBuffers();
}

// callback de redesenho da janela glut
void alterarTamanhoJanelaU7E2(GLsizei w, GLsizei h) {
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void gerenciarMouseU7E2(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-out
			if (angle <= 130) angle += 5;
		}
	glutPostRedisplay();
}

// Inicializa parâmetros de iluminação
void inicializarU7E2(void) {

	GLfloat luzAmbiente[4] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 }; // "cor"
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho"
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	angle = 45;
}
