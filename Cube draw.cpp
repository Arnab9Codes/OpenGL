// Cube Draw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <GLUT.H>

static float a=75,r=1,n=5,f=220;
static float ex=5,ey=5,ez=5,cx=0,cy=0,cz=0,upx=0,upy=0,upz=1;

void init(){
	
	glClearColor(.1,.1,.1,0.5);
}

void cube()
{
	glBegin(GL_QUADS);
	//q1
	glColor3f(0.2,0.6,0.5);
	glVertex3f(1.0f,1.0f,0.0f);//1
	glVertex3f(1.0f,0.0f,0.0f);//2
	glVertex3f(1.0f,0.0f,1.0f);//3
	glVertex3f(1.0f,1.0f,1.0f);//4
	//q2
	glColor3f(0.6,0.6,0.5);
	glVertex3f(1.0f,0.0f,0.0f);//2
	glVertex3f(0.0f,0.0f,0.0f);//7
	glVertex3f(0.0f,1.0f,0.0f);//5
	glVertex3f(1.0f,1.0f,0.0f);//1
	//q3
	glColor3f(0.6,0.6,0.9);
	glVertex3f(0.0f,1.0f,0.0f);//5
	glVertex3f(0.0f,1.0f,1.0f);//6
	glVertex3f(0.0f,0.0f,1.0f);//8
	glVertex3f(0.0f,0.0f,0.0f);//7
	//q4
	glColor3f(0.3,0.6,0.3);
	glVertex3f(0.0f,1.0f,0.0f);//5
	glVertex3f(0.0f,1.0f,1.0f);//6
	glVertex3f(1.0f,1.0f,1.0f);//4
	glVertex3f(1.0f,1.0f,0.0f);//1
	//q5
	glColor3f(0.72,0.67,0.95);
	glVertex3f(0.0f,0.0f,0.0f);//7
	glVertex3f(0.0f,0.0f,1.0f);//8
	glVertex3f(1.0f,0.0f,1.0f);//3
	glVertex3f(1.0f,0.0f,0.0f);//2
	//q6
	glColor3f(0.9,0.6,0.9);
	glVertex3f(0.0f,1.0f,1.0f);//6
	glVertex3f(0.0f,0.0f,1.0f);//8
	glVertex3f(1.0f,0.0f,1.0f);//3
	glVertex3f(1.0f,1.0f,1.0f);//4

	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(a,r,n,f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(ex,ey,ez,cx,cy,cz,upx,upy,upz);
	cube();
	glFlush();

}
void keyboard(unsigned char key, int x,int y)
{
	switch(key){
	
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
	case 'h':  
		 cx=cx+2;   
		  glutPostRedisplay(); 
  		break; 
	 case 'j':  
		 cy=cy+2;  
		 glutPostRedisplay();  
		break;  
	case 'k':  
		 cz=cz+2; 
		 glutPostRedisplay(); 
		break; 
		 
     case '1': 
		 cx=cx-2; 
		 glutPostRedisplay(); 
		break; 
	 case '2': 
		 cy=cy-2; 
		 glutPostRedisplay(); 
		break; 
   	 case '3':
		 cz=cz-2; 
		 glutPostRedisplay();	 	
		 break; 
	case 'i': 
		r=r+0.2; 
		glutPostRedisplay(); 		
		break; 
	case 'o': 
		r=r-0.2; 
		glutPostRedisplay(); 		
		break; 
	case 'z': 
		a=a+5; 
		glutPostRedisplay(); 		
		break; 
	case 'x': 
		a=a-5; 
		glutPostRedisplay(); 
		break; 
	case 'c': 
		n=n+5; 
		glutPostRedisplay(); 		
		break; 
	case 'v': 
		n=n-5; 
 		glutPostRedisplay();
 		break;
 	case 'b':
 		f=f+5;
 		glutPostRedisplay();		
 		break;
 	case 'n':
 		f=f-5;
 		glutPostRedisplay();
 		break;
	case '7':
		upx=1.0;
		upy=0.0;
		upz=0.0;glutPostRedisplay();
		break;
	case '8':
		upx=0.0;
		upy=1.0;
		upz=0.0;glutPostRedisplay();
		break;
	case '9':
		upx=0.0;
		upy=0.0;
		upz=1.0;glutPostRedisplay();
		break;

	 default:
		 break;
	}
}




int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;


}


