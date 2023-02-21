#include <stdlib.h>
#include "GL/glut.h"
#include <iostream>
#include <math.h>
#pragma comment(lib, "glut32.lib")
#define WINDOW_TITLE "Project"
using namespace std;

int m_iWidth = 800;
int m_iHeight = 600;


void keyboardDown(unsigned char key, int x, int y){

  switch(key) {
  case 'Q':
  case 'q':
  case  27:
	  exit(0);
  }
}


void idle(void){
	glutPostRedisplay();
}


void draw(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6,0.6,0.6,1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
	glBegin(GL_TRIANGLES);
        glColor3f( 1, 0, 0 );
        glVertex2f( -0.8, -0.8 );
        glColor3f( 0, 1, 0 );
        glVertex2f( 0.8, -0.8 );
        glColor3f( 0, 0, 1 );
        glVertex2f( 0, 0.9 );
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f( -0.5, -0.5, -0.5);
        glVertex3f( -0.5,  0.5, -0.5);
        glVertex3f(  0.5,  0.5, -0.5);
        glVertex3f(  0.5, -0.5, -0.5);
    glEnd();

	glutSwapBuffers();
}


void reshape(int width, int height){
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  float ratio = (height == 0)?1:(GLfloat) width/(GLfloat) height;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


bool initialize(){
	glEnable(GL_DEPTH_TEST);
	return true;
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(m_iWidth, m_iHeight);
	glutCreateWindow(WINDOW_TITLE);
	if(!initialize()) return 1;
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardDown);
	glutMainLoop();
	return 0;
}
