#include<windows.h>
#include<GL/glut.h>

void DisplayGL(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0.0f, 0.0f, -6.0f );
    glRotatef( g_fRotate1, 0.0f, 1.0f, 0.0f);
    glBegin( GL_QUADS );
    glColor3f(   0.0f,  1.0f,   0.0f ); // Green
    glVertex3f(  1.0f,  1.0f,  -1.0f ); // Top-right of the Top face
    glVertex3f( -1.0f,  1.0f,  -1.0f ); // Top-left of the Top face
    glVertex3f( -1.0f,  1.0f,   1.0f ); // Buttom-left of the Top Face
    glVertex3f(  1.0f,  1.0f,   1.0f ); // Buttom-right of the Top Face
    // Bottom face
    glColor3f(   1.0f,  0.5f,  0.0f ); // Orange
    glVertex3f(  1.0f, -1.0f, -1.0f ); // Top-right of the Bottom face
    glVertex3f( -1.0f, -1.0f, -1.0f ); // Top-left of the Bottom face
    glVertex3f( -1.0f, -1.0f,  1.0f ); // Buttom-left of the Bottom face
    glVertex3f(  1.0f, -1.0f,  1.0f ); // Buttom-right of the Bottom face
    // Front face
    glColor3f(   1.0f,  0.0f,  0.0f ); // Red
    glVertex3f(  1.0f,  1.0f,  1.0f ); // Top-right of the Front face
    glVertex3f( -1.0f,  1.0f,  1.0f ); // Top-left of the Front face
    glVertex3f( -1.0f, -1.0f,  1.0f ); // Buttom-left of the Front face
    glVertex3f(  1.0f, -1.0f,  1.0f ); // Buttom-right of the Front face
    // Back face
    glColor3f(   1.0f,  1.0f,  0.0f ); // Yellow
    glVertex3f(  1.0f, -1.0f, -1.0f ); // Top-right of the Back face
    glVertex3f( -1.0f, -1.0f, -1.0f ); // Top-left of the Back face
    glVertex3f( -1.0f,  1.0f, -1.0f ); // Buttom-left of the Back face
    glVertex3f(  1.0f,  1.0f, -1.0f ); // Buttom-right of the Back face
    // Left face
    glColor3f(   0.0f,  0.0f,  1.0f ); // Blue
    glVertex3f( -1.0f,  1.0f,  1.0f ); // Top-right of the Left face
    glVertex3f( -1.0f,  1.0f, -1.0f ); // Top-left of the Left face
    glVertex3f( -1.0f, -1.0f, -1.0f ); // Buttom-left of the Left face
    glVertex3f( -1.0f, -1.0f,  1.0f ); // Buttom-right of the Left face
    // Right face
    glColor3f(   1.0f,  0.0f,  1.0f ); // Violet
    glVertex3f(  1.0f,  1.0f,  1.0f ); // Top-right of the Right face
    glVertex3f(  1.0f,  1.0f, -1.0f ); // Top-left of the Right face
    glVertex3f(  1.0f, -1.0f, -1.0f ); // Buttom-left of the Right face
    glVertex3f(  1.0f, -1.0f,  1.0f ); // Buttom-right of the Right face
    glEnd();

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowPosition( 300, 300 );
    glutInitWindowSize( 300, 300 );
    glutDisplayFunc(DisplayGL);
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
}
