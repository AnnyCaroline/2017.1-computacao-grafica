#include <GL/glut.h>
#include "camera.h"
#include "plataform.h"
#include "robot.h"
#include "runner.h"

int Runner::Width = 800;
int Runner::Height = 800;
int Runner::pos_mouse_x;
int Runner::pos_mouse_y;
Robot Runner::robot;
Camera Runner::camera;
Plataform Runner::plataform;


int main(int argc, char** argv){
	Runner::run(argc, argv);
}