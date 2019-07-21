// Unidade 6 - Exemplo 5: Braço Mecânico 2D

#include <GL/freeglut.h>
#define PI 3.141592654
#define tAnima 5.0
#define deltaT 33

// Funções callback
void desenharU6E5(void);
void lerTecladoU6E5(unsigned char key, int x, int y);
void setTimerU6E5(int value);
void alterarTamanhoJanelaU6E5(GLsizei w, GLsizei h);


// Variáveis globais
float theta1, theta2, thetaMax, thetaMin, hMax, h0, h1, h2, incremento;


void mainU6E5(void) {
	h0 = 6; h1 = 4; h2 = 2;
	hMax = h0 + h1 + h2;
	theta1 = theta2 = 0;
	thetaMax = PI / 2;
	thetaMin = -PI / 2;
	incremento = 0.1;

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Braço Mecânico 2D");
	glutPositionWindow(200, 100);
	glutReshapeWindow(200, 400);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, hMax, -hMax, hMax);

	glutDisplayFunc(desenharU6E5);
	glutKeyboardFunc(lerTecladoU6E5);
	glutTimerFunc(deltaT, setTimerU6E5, 1);
	glutReshapeFunc(alterarTamanhoJanelaU6E5);
}

void desenharU6E5(void) {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(20);
	/* haste 0 */
	glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex2f(0.0, 0.0);
		glVertex2f(h0, 0.0);
	glEnd();

	/* haste 1 */
	glTranslatef(h0, 0, 0);
	glRotatef(180.0*theta1 / PI, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex2f(0.0, 0.0);
		glVertex2f(h1, 0.0);
	glEnd();

	/* haste 2 */
	glTranslatef(h1, 0, 0);
	glRotatef(180.0*theta2 / PI, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glColor3f(0, 1, 0);
		glVertex2f(0.0, 0.0);
		glVertex2f(h2, 0.0);
	glEnd();

	glutSwapBuffers();
}

void lerTecladoU6E5(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
}

void setTimerU6E5(int value) {
	theta1 = theta1 + incremento;
	if ((theta1 >= thetaMax) || (theta1 <= thetaMin)) incremento *= -1;
	theta2 = theta1 * 2;
	glutPostRedisplay();
	glutTimerFunc(deltaT, setTimerU6E5, 1);
}

void alterarTamanhoJanelaU6E5(GLsizei w, GLsizei h) {
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, h / 2, h);
}

void inicializarU6E5(void) {
	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}