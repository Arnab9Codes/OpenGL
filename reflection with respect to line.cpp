// line reflection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GLUT.H>
#include <stdio.h>


void display()
{
	glBegin(GL_POLYGON);
	glColor3f(0.8,0.3,0.7);
	glVertex2f(0.3,0.5);
	glColor3f(0.5,0.3,0.97);
	glVertex2f(0.5,0.5);
	glColor3f(0.8,0.23,0.7);
	glVertex2f(0.7,0.7);
	glColor3f(0.08,0.3,0.87);
	glVertex2f(0.4,0.9);
	glColor3f(0.5,0.33,0.79);
	glVertex2f(0.1,0.7);
	glColor3f(0.99,0.3,0.7);
	glVertex2f(0.3,0.5);
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int x,int y)
{

	switch(key){

	case 'a':
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.0,0.05,0.0);
		glRotatef(25,0,0,1);
		glScalef(1,-1,1);
		glRotatef(-25,0,0,1);
		glTranslatef(0.0,-0.05,0.0);
		//glutDisplayFunc(display);
		break;
	default:
		break;

	}//switch
	glutPostRedisplay();
}
 
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(900,0);
	
	glutCreateWindow("reflection");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	
	
	return 0;
}

