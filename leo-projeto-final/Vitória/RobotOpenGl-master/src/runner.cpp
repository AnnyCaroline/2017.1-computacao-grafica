#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "plataform.h"
#include "camera.h"
#include "robot.h"
#include "runner.h"
using namespace std;

Runner::Runner(){
	Robot robot;
	Camera camera; 
	Plataform plataform;
}


void Runner::run(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Robot");
	initLighting();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(moving_mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

void Runner::reshape(int width, int height){
	Width = width;
	Height = height;
	glutPostRedisplay();
}

void Runner::initLighting(void){
	GLfloat lightposition[] = { 3.0, -3.0, 3.0, 0.0 };
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

// keyboard callback
void Runner::keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 27:
		exit(0); break;
	case 'a': 
		robot.setPositionX(-0.1);
		robot.setDirection(-90.0);
		break;
	case 's':
		robot.setPositionY(0.1);  
		robot.setDirection(0.0);
		break;
	case 'd':
		robot.setPositionX(0.1); 
		robot.setDirection(90.0);
		break;
	case 'w':
		robot.setPositionY(-0.1);  
		robot.setDirection(180.0);
		break;
	case '+':
		camera.setZoom(-1);
		break;
	case '-':
		camera.setZoom(1);
		break;
	default:
		return; 
	}
	glutPostRedisplay();
}
void Runner::moving_mouse(int x, int y){

	if (x != pos_mouse_x || y != pos_mouse_y){

		if (x < pos_mouse_x){
			camera.setAlpha(0.1);	
		}else if (x > pos_mouse_x){
			camera.setAlpha(-0.1);
		}
		if (y < pos_mouse_y){
			camera.setBeta(1.0);
		}else if (y > pos_mouse_y){
			camera.setBeta(-1.0);
		}
		pos_mouse_x = x;
		pos_mouse_y = y;
	}
		
	glutPostRedisplay();
}
	
void Runner::mouse(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if (x != pos_mouse_x || y != pos_mouse_y){

		
			if (x < pos_mouse_x){
				camera.setAlpha(0.1);	
			}else if (x > pos_mouse_x){
				camera.setAlpha(-0.1);
			}
			if (y < pos_mouse_y){
				camera.setBeta(1.0);
			}else if (y > pos_mouse_y){
				camera.setBeta(-1.0);
			}
			pos_mouse_x = x;
			pos_mouse_y = y;
		}
	}
	glutPostRedisplay();
}

//draw callback
void Runner::display(void){
	double x = robot.getPositionX();
	double y = robot.getPositionY();
	camera.view(x, y);
	plataform.draw();
	robot.draw();

	glutSwapBuffers();
}