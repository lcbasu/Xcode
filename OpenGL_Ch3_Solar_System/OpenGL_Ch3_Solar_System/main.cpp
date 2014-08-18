//
//  main.cpp
//  OpenGL_Ch3_Solar_System
//
//  Created by Lokesh Basu on 18/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

static float _angleYear = 0.0f, _angleDay = 0.0f, _angleSun = 0.0f, _angleMoon = 0.0f;

void init()
{
    /* draw smaller planet */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f (1.0, 1.0, 0.0);
    glRotatef (_angleSun, 0.0, 1.0, 0.0);
    glutWireSphere(1.0, 200, 16);
    glRotatef (_angleYear, 0.0, 1.0, 0.0);
    glTranslatef (2.0, 0.0, 0.0);
    glColor3f (0.0, 0.0, 1.0);
    glRotatef (_angleDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.3, 100, 8);         //earth
    glColor3f (1.0, 1.0, 1.0);
    glRotatef (_angleMoon, 2.0, 0.0, 0.0);
    glTranslatef (0.5, 0.0, 0.0);
    glutWireSphere(0.1, 50, 8);    //moon
    glPopMatrix();
    
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt (5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void update(int value)
{
    _angleYear += 2.0f;
    _angleDay += 2.0f;
    _angleSun += 0.5f;
    _angleMoon += 0.2f;
    if (_angleYear > 360) {
        _angleYear -= 360;
    }
    if (_angleDay > 360) {
        _angleDay -= 360;
    }
    if (_angleSun > 360) {
        _angleSun -= 360;
    }
    if (_angleMoon > 360) {
        _angleMoon -= 360;
    }
    
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1100, 600);
    glutInitWindowPosition (80, 80);
    glutCreateWindow ("Solar System");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}