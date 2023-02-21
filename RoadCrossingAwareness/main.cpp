#include <stdio.h>
 #include <GL/gl.h>
 #include <GL/glut.h>
 #include <math.h>

// Function Prototypes
void specialKeys();

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
double tx=0;
double ty=0;
double tz=0;
double sx=0;
double sy=0;

void draw_cube()
{
//Multi-colored side - FRONT
  glBegin(GL_POLYGON);

  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

  glEnd();

  // Cyan side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
}


// display() Callback functions
void display_T(){
   //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   // Reset transformations
  glLoadIdentity();
  glRotatef( 15, 0.0, 1.0, 0.0 );
  glTranslatef( tx, 0.0, 0.0 );
  glTranslatef( 0.0, ty, 0.0 );
  glTranslatef( 0.0, 0.0, tz);
  draw_cube();
  glFlush();
  glutSwapBuffers();
 }

void display_R(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0);
  draw_cube();
  glFlush();
  glutSwapBuffers();
 }




void display_S(){
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glScalef( sx, sy, 0.0 );
   glRotatef( 15, 0.0, 1.0, 0.0 );
   glRotatef( 25, 1.0, 0.0, 0.0 );
   glRotatef( 5, 0.0, 0.0, 1.0 );
   draw_cube();
   glFlush();
   glutSwapBuffers();
 }

// specialKeys() Callback Function
void specialKeys( int key, int x, int y ) {

    if (key == GLUT_KEY_RIGHT){                  //Translatation along forward x-axis
    tx+=0.1;
    }
  else if (key == GLUT_KEY_LEFT){		//Translatation along backward x-axis
    tx-=0.1;
    }
  else if (key == GLUT_KEY_UP){			//Translatation along upward y-axis
    ty+=0.1;
    }
  else if (key == GLUT_KEY_DOWN){              //Translatation along downward y-axis
    ty-=0.1;
    }
  else if (key == GLUT_KEY_F9){		      //Translatation along z-axis
    tz+=0.2;
   }
  else if (key == GLUT_KEY_F10){	     //Translatation along z-axis
    tz-=0.2;
   }
  else if (key == GLUT_KEY_F1 )              //Rotation about Z axis anti-cloclwise
  {
  rotate_z += 5;
  }
 else if (key == GLUT_KEY_F2 ) 	   	    //Rotation about Z axis cloclwise
  {
  rotate_z -= 5;
  }
 else if (key == GLUT_KEY_F3 )             //Rotation about Y axis anti-cloclwise
{
rotate_y += 5;
}
else if (key == GLUT_KEY_F4 ) 		  //Rotation about Y axis cloclwise
{
rotate_y -= 5;
}
else if (key == GLUT_KEY_F5 )             //Rotation about X axis anti-cloclwise
{
rotate_x += 5;

}
else if (key == GLUT_KEY_F6 ) 		//Rotation about X axis cloclwise
{
rotate_x -= 5;
    }
else if (key == GLUT_KEY_F7 )                          //Scaling-UP
{
    sx=1.5;
    sy=1.5;
}
else if (key == GLUT_KEY_F8 ) 				//Scaling-down
{
    sx=0.5;
    sy=0.5;
}
 glutPostRedisplay();
}

void win_init()
{
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowPosition(0, 0);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Awesome Cube");
 glEnable(GL_DEPTH_TEST);
}


int main(int argc, char* argv[]){
int ch;
glutInit(&argc,argv);
 do{
printf("\n  1.Translation \n  2.Rotation\n  3.Scaling \n4. Exit");
	     printf("\n Enter ur chioce:");
	     scanf("%d",&ch);
	     switch(ch)
	     {
case 1:
             win_init();
             glutDisplayFunc(display_T);
             glutSpecialFunc(specialKeys);
             glutMainLoop();
break;

case 2:
	     win_init();
             glutDisplayFunc(display_R);
             glutSpecialFunc(specialKeys);
             glutMainLoop();
break;

case 3:
             win_init();
             glutDisplayFunc(display_S);
             glutSpecialFunc(specialKeys);
             glutMainLoop();
break;

}
}while(ch!=4);

   return 0;
 }
