
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

using std::cout; using std::endl; using std::string;

class funcs{
public:
	float a(float x);
	float b(float x);
	float c(float x);
	float d(float x);
};
float funcs::a(float x){
	float y;
		y = x*x;
	return y;
}
float funcs::b(float x){
	float y;
	y = sin(x);
	return y;
}
float funcs::c(float x){
	float y;
	y = cos(x);
	return y;
}
float funcs::d(float x){
	float y;
	return y;
}

void display(){
	const int win_width =glutGet(GLUT_WINDOW_WIDTH);
	const int win_height=glutGet(GLUT_WINDOW_HEIGHT);
	const float win_aspect = float(win_width) / float(win_height);
	funcs myfuncs;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0,0,win_width, win_height);
	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
	glOrtho(-win_aspect, win_aspect,-1,1,0.8,100);
	gluLookAt(0,0,5,0,0,0,0,1,0);

	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex3f(2 ,2,0);
		glVertex3f(-2,2,0);
		glColor3f(0,0.5,0.5);
		glVertex3f(-2 ,0,0);
		glVertex3f(2,0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glColor3f(1,0.75,0);
		for(int i = 0; i <= 90; i++)
		{
			glVertex3f(myfuncs.b(float(i))/2,myfuncs.c(float(i))/2-0.18,0);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i = 0; i < 20; i++)
		{
			glColor3f(1,1-(float(i)/20),0);
			glVertex3f(float(i)/50,(-myfuncs.a(float(i)/20)/4)+0.25,0);
			glVertex3f(-float(i)/50,(-myfuncs.a(float(i)/20)/4)+0.25,0);
		}
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0,0,0.25);
		glVertex3f(2,0,0);
		glVertex3f(-2,0,0);
		glColor3f(0,0.25,0.25);
		glVertex3f(-2,-2,1);
		glVertex3f(2,-2,1);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glColor3f(0,0,1);
		for(int i = 0; i < 10; i++)
		{
			glVertex3f(float(i)/5,-myfuncs.a(float(i)/10),float(i)/10);
			glVertex3f(-float(i)/5,-myfuncs.a(float(i)/10),float(i)/10);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		glColor3f(0,1,1);
		for(int i = 0; i < 10; i++)
		{
			glVertex3f(float(i)/8,-myfuncs.a(float(i)/10),float(i)/10);
			glVertex3f(-float(i)/8,-myfuncs.a(float(i)/10),float(i)/10);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		glColor3f(1,0.5,0);
		for(int i = 0; i < 10; i++)
		{
			glVertex3f(float(i)/10,-myfuncs.a(float(i)/10),float(i)/10);
			glVertex3f(-float(i)/10,-myfuncs.a(float(i)/10),float(i)/10);
		}
	glEnd();
	glBegin(GL_LINE_STRIP);
		for(int i = 0; i < 10; i++)
		{
			glColor3f(1,0+float(i)/10,0);
			glVertex3f(float(i)/15,-myfuncs.a(float(i)/10),float(i)/10);
			glVertex3f(-float(i)/15,-myfuncs.a(float(i)/10),float(i)/10);
		}
	glEnd();
	glFlush();

}

int main(int argc, char** argv){
	
	cout << "Hello GL" << endl;
	glutInit( &argc, argv );
	glutCreateWindow("Assignment 1 - Behnam Saeedi");
	glutInitWindowSize(800,600);
	glutInitWindowPosition(50,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
