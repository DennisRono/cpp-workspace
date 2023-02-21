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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(1220, 800);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Road Crossing Awareness");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
