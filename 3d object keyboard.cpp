// 3d object keyboard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



// 3d object perpective view control.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<glut.h>

static float ex=10,ey=10,ez=10,upx=0,upy=0,upz=1;
static float fova=80,asr=1,near=10,far=200;

void init(void)
{
	glClearColor (0.0, 0.0, 08.0, 0.0);
	glShadeModel (GL_FLAT);
}

void DrawCube(void)
{

glBegin(GL_QUAD_STRIP);
  
    glVertex3f( 1.50f, 1.50f, 1.50f);   
    glVertex3f( 1.50f,-1.50f, 1.50f);  
    glVertex3f( 1.50f, 1.50f,-1.50f);   
    glVertex3f( 1.50f,-1.50f,-1.50f);   
    glVertex3f(-1.50f, 1.50f,-1.50f);   
    glVertex3f(-1.50f,-1.50f,-1.50f);   
    glVertex3f(-1.50f, 1.50f, 1.50f);  
    glVertex3f(-1.50f,-1.50f, 1.50f);   
    glVertex3f( 1.50f, 1.50f, 1.50f);   
    glVertex3f( 1.50f,-1.50f, 1.50f);   
glEnd();/**
glBegin(GL_QUADS);
  //Quad 5
    glVertex3f(-1.0f, 1.0f,-1.0f);   
    glVertex3f(-1.0f, 1.0f, 1.0f);   
    glVertex3f( 1.0f, 1.0f, 1.0f);   
    glVertex3f( 1.0f, 1.0f,-1.0f);   
  //Quad 6
    glVertex3f(-1.0f,-1.0f, 1.0f);   
    glVertex3f(-1.0f,-1.0f,-1.0f);   
    glVertex3f( 1.0f,-1.0f,-1.0f);   
    glVertex3f( 1.0f,-1.0f, 1.0f);   
glEnd();**/
}

void display()
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(fova,asr, near, far);
	glMatrixMode(GL_MODELVIEW);
		
	glLoadIdentity (); /* clear the matrix */

	gluLookAt (ex, ey, ez, 0.0, 0.0, 0.0, upx, upy, upz);
	//gluPerspective(fova,asr, near, far);

	glScalef (1.0, 2.0, 1.0);
	//glutWireCube (2.0);
	DrawCube();


	glFlush ();

	
}

void keyboard(unsigned char key, int x, int y)
{    
	
     switch(key)
     {

     case 'q':
		 ex=ex+2;
		 glutPostRedisplay();
		break;
	 case 'w':
		 ey=ey+2;
		 glutPostRedisplay();
		break;
	case 'e':
		 ez=ez+2;
		 glutPostRedisplay();
		break;
		
     case 'a':
		 ex=ex-2;
		 glutPostRedisplay();
		break;
	 case 's':
		 ey=ey-2;
		 glutPostRedisplay();
		break;
	case 'd':
		 ez=ez-2;
		 glutPostRedisplay();		
		 break;
	case '8':
		upx=1;upy=0;upz=0;
		glutPostRedisplay();		
		break;
	case '9':
		upx=0;upy=1;upz=0;
		glutPostRedisplay();		
		break;
	case '7':
		upx=0;upy=0;upz=1;
		glutPostRedisplay();		
		break;
	case 'i':
		asr=asr+0.2;
		glutPostRedisplay();		
		break;
	case 'o':
		asr=asr-0.2;
		glutPostRedisplay();		
		break;
	case 'z':
		fova=fova+5;
		glutPostRedisplay();		
		break;
	case 'x':
		fova=fova-5;
		glutPostRedisplay();
		break;
	case 'c':
		near=near+5;
		glutPostRedisplay();		
		break;
	case 'v':
		near=near-5;
		glutPostRedisplay();
		break;
	case 'b':
		far=far+5;
		glutPostRedisplay();		
		break;
	case 'n':
		far=far-5;
		glutPostRedisplay();
		break;
	default:
		break;
	
     }
glutPostRedisplay();
     }

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();

	return 0;
}


