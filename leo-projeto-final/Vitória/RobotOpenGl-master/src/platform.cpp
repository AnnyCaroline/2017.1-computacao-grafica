#include "plataform.h"
#include <GL/glut.h>


Plataform::Plataform(){}


void Plataform::draw(){
	//Plataforma
	glPushMatrix();
		drawplataform();
	glPopMatrix();
	glPushMatrix();
		drawring();	
	glPopMatrix();
}
void Plataform::drawplataform(){
	glColor3f(1, 1, 1);
    glScalef(30,3.0,30);
    glTranslatef(0, 0, 0);
    glutSolidCube(1);
}

void Plataform::drawring(){
	glColor3f(1, 0, 0);
	glPushMatrix();
		glTranslatef(15, 0, 15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(15, 0, -15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-15, 0, -15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(0.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(0.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-15, 0, 15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(15, 0, 15);
		glTranslatef(0.0, 0.0, 0.1);

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();
}
