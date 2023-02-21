#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <GL/glew.h>
#define FREEGLUT_STATIC
#include <GL/freeglut.h>

using namespace std;

void draw(){

}

void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  GLfloat aspect = GLfloat(w) / GLfloat(h);
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
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
