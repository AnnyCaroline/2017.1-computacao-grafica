#include "robot.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;

Robot::Robot(){
	current_alpha = 0;
	pos_x = 0;
	pos_y = 0;
	current_direction = 0.0;
}


void Robot::draw(){
	glTranslatef(pos_x,4.0, pos_y);

	glRotatef(current_direction, 0.0, 1.0, 0.0);
	//cout << current_direction;
	glPushMatrix();
		glPushMatrix();
			glPushMatrix();
				drawbody();
			glPopMatrix();
			//desenha braco
			drawarm(1);
		glPopMatrix();
		drawarm(-1);
	glPopMatrix();
	//desenha cabeca
	drawhead();

}
void Robot::drawplataform(){
	glColor3f(0, 1, 1);
        glScalef(25,3.0,25);
        glTranslatef(0, 0, 0);
        glutSolidCube(1);
}

void Robot::drawbody(){
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(1.0);

	//desenha esfera
	glTranslatef(0.0,-1.5, 0.0);
	glutSolidSphere(1.0,50.0, 50.0);
}
void Robot::drawhead(){
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0,0.0,1.1);
	glutSolidSphere(0.6, 30.0,30.0);
}
void Robot::drawarm(int arm){
	glRotatef(arm*90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.5);
	glutSolidSphere(0.2, 30.0,30.0);
	glTranslatef(0.0, 0.0, 0.1);
	glRotatef(15.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 0.1, 0.1, 1.0, 30.0, 30.0);
	glTranslatef(0.0, 0.0, 0.9);
	glutSolidSphere(0.2, 30.0,30.0);
	glRotatef(-60.0*arm, 0.0, 1.0, 0.0);
	glRotatef(60.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.1);
	gluCylinder(gluNewQuadric(), 0.1, 0.1, 0.7, 30.0, 30.0);
	glTranslatef(0.0, 0.0, 0.6);
	glutSolidSphere(0.2, 30.0,30.0);
	glPushMatrix();
		glRotatef(60.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.1);
		gluCylinder(gluNewQuadric(), 0.05, 0.05, 0.3, 30.0, 30.0);
		glTranslatef(0.0, 0.0, 0.3);
		glutSolidSphere(0.1, 30.0,30.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.1);
		glutWireCone(0.05, 0.3,50, 50);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-60.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.1);
		gluCylinder(gluNewQuadric(), 0.05, 0.05, 0.3, 30.0, 30.0);
		glTranslatef(0.0, 0.0, 0.3);
		glutSolidSphere(0.1, 30.0,30.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.05);
		glutWireCone(0.05, 0.3,50, 50);
	glPopMatrix();

}
void Robot::setPositionX(double x){
	if (pos_x + x <13 && pos_x + x > -13){
		pos_x += x;
	}
}
void Robot::setPositionY(double y){
	if (pos_y + y <13 && pos_y + y > -13){
		pos_y += y;
	}
}

void Robot::setDirection(int direction){
	current_direction = direction;
}

double Robot::getPositionX(){
	return pos_x;
}

double Robot::getPositionY(){
	return pos_y;
}