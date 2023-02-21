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

    int width = 1220;
    int height = 800;
    glutInitWindowSize(width, height);
    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("Road Crossing Awareness");
    printf("window id: %d\n", win);
    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}
