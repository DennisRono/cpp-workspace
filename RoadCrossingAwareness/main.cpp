#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

#include <GL/glew.h>

#define FREEGLUT_STATIC
#include <GL/freeglut.h>

using namespace std;

int g_iWindowWidth = 1000, g_iWindowHeight = 800, g_hWindowHandle = 0;

clock_t g_PreviousTicks, g_CurrentTicks;

float g_fRotationRate = 50.0; // degree per second
float g_fRotate1 = 0.0f;

void InitGLUT(int argc, char* argv[]);

void DisplayGL();
void IdleGL();
void KeyboardGL( unsigned char c, int x, int y);
void MouseGL( int button, int state, int x, int y );
void MotionGL( int x, int y );
void ReshapeGL( int w, int h );


int main( int argc, char* argv[] )
{
    InitGLUT( argc, argv );

    g_PreviousTicks = clock();
    glutMainLoop();

    // return 0;
    // system("PAUSE");
}

void InitGLUT( int argc, char* argv[] )
{
    glutInit( &argc, argv );

    glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION );

    int iScreenWidth = glutGet( GLUT_SCREEN_WIDTH );
    int iScreenHeight = glutGet( GLUT_SCREEN_HEIGHT );

    glutInitDisplayMode( GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH );

    glutInitWindowPosition( ( iScreenWidth - g_iWindowWidth ) / 2, ( iScreenHeight - g_iWindowHeight ) / 2 );
    glutInitWindowSize( g_iWindowHeight, g_iWindowWidth );

    g_hWindowHandle = glutCreateWindow("OpenGL Template");

    glutDisplayFunc(DisplayGL);
    glutIdleFunc(IdleGL);
    glutKeyboardFunc(KeyboardGL);
    glutMouseFunc(MouseGL);
    glutMotionFunc(MotionGL);
    glutReshapeFunc(ReshapeGL);

    glEnable( GL_DEPTH_TEST );
}

// Desc: Display the cube
void DisplayGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // glScalef(0.25f, 0.25f, 2.0f);
    glTranslatef( 0.0f, 0.0f, -6.0f );

    glRotatef( g_fRotate1, 0.0f, 1.0f, 0.0f);

    // Render the cube
    glBegin( GL_QUADS );

    // Top face
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

void IdleGL()
{
    g_CurrentTicks = clock();
    float deltaTicks = (float)( g_CurrentTicks - g_PreviousTicks);
    g_PreviousTicks = g_CurrentTicks;

    float fDetaTime = deltaTicks / (float) CLOCKS_PER_SEC;

    g_fRotate1 +=  ( 10 * g_fRotationRate * fDetaTime );
    g_fRotate1 = fmodf( g_fRotate1, 360.0f );
}

// Desc: Keyboard input handle
void KeyboardGL( unsigned char c, int x, int y)
{
    cout << "Key Pressed " << (int)c << endl;

    switch(c)
    {
        case '1':
            break;
        case '2':
            break;
        // press esc to escape
        case 27:
            glutLeaveMainLoop();
            break;

    }
}

void MouseGL( int button, int state, int x, int y )
{

}

void MotionGL( int x, int y )
{

}

void glhFrustumf2(float *matrix, float left, float right, float bottom, float top,
                  float znear, float zfar)
{
    float temp, temp2, temp3, temp4;
    temp = 2.0 * znear;
    temp2 = right - left;
    temp3 = top - bottom;
    temp4 = zfar - znear;
    matrix[0] = temp / temp2;
    matrix[1] = 0.0;
    matrix[2] = 0.0;
    matrix[3] = 0.0;
    matrix[4] = 0.0;
    matrix[5] = temp / temp3;
    matrix[6] = 0.0;
    matrix[7] = 0.0;
    matrix[8] = (right + left) / temp2;
    matrix[9] = (top + bottom) / temp3;
    matrix[10] = (-zfar - znear) / temp4;
    matrix[11] = -1.0;
    matrix[12] = 0.0;
    matrix[13] = 0.0;
    matrix[14] = (-temp * zfar) / temp4;
    matrix[15] = 0.0;
}

void glhPerspectivef2(float *matrix, float fovyInDegrees, float aspectRatio,
                      float znear, float zfar)
{
    float ymax, xmax;
    float temp, temp2, temp3, temp4;
    ymax = znear * tanf(fovyInDegrees * M_PI / 360.0);
    //ymin = -ymax;
    //xmin = -ymax * aspectRatio;
    xmax = ymax * aspectRatio;
    glhFrustumf2(matrix, -xmax, xmax, -ymax, ymax, znear, zfar);
}


void ReshapeGL( int w, int h )
{
    if ( h == 0 )
        h = 1;

    g_iWindowWidth = w;
    g_iWindowHeight = h;

    glViewport( 0, 0, g_iWindowWidth, g_iWindowHeight );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glhPerspectivef2( 60.0f*, g_iWindowWidth / (GLdouble) g_iWindowHeight, 0.1, 100.0 );

    glutPostRedisplay();

}
