#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <GL/glew.h>
#define FREEGLUT_STATIC
#include <GL/freeglut.h>

using namespace std;

void road()
{
glPushMatrix();
glScaled(40.0,40.0,0.0);
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
//straight road
glVertex2f(0,5);
glVertex2f(40,5);
glVertex2f(40,10);
glVertex2f(0,10);
glEnd();
//green edge
glBegin(GL_POLYGON);
glColor3f(0.1,0.2,0.1);
glVertex2f(0,5);
glVertex2f(40,5);
glVertex2f(40,4);
glVertex2f(0,4);
glEnd();
//cross road
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(0,10);
glVertex2f(15,10);


glEnd();
glPopMatrix();
}

void draw(){
    road();
}

void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  GLfloat aspect = GLfloat(w) / GLfloat(h);
  glLoadIdentity();
  if (w <= h) {
    glOrtho(-2.5, 2.5, -2.5/aspect, 2.5/aspect, -10.0, 10.0);
  } else {
    glOrtho(-2.5*aspect, 2.5*aspect, -2.5, 2.5, -10.0, 10.0);
  }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(1220, 800);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Road Crossing Awareness");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
