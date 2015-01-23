//
//  main.cpp
//  OpenGLProgramming
//
//  Created by Lokesh Basu on 09/12/14.
//  Copyright (c) 2014 InHouse. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "glm.hpp"
#include "matrix_transform.hpp"
#include "quaternion.hpp"
#include "type_ptr.hpp"

float _angle = 0;
float _scaleValue = 0.1;

void drawCube(float size)
{
    glBegin(GL_QUADS);
    //front face
    glColor3f(1, 0, 0);
    glVertex3f(size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, size/2);
    glVertex3f(-size/2, -size/2, size/2);
    glVertex3f(size/2, -size/2, size/2);
    
    //left face
    glColor3f(0, 1, 0);
    glVertex3f(-size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, -size/2);
    glVertex3f(-size/2, -size/2, -size/2);
    glVertex3f(-size/2, -size/2, size/2);
    
    //back face
    glColor3f(0, 0, 1);
    glVertex3f(size/2, size/2, -size/2);
    glVertex3f(-size/2, size/2, -size/2);
    glVertex3f(-size/2, -size/2, -size/2);
    glVertex3f(size/2, -size/2, -size/2);
    
    //right face
    glColor3f(1, 1, 0);
    glVertex3f(size/2, size/2, -size/2);
    glVertex3f(size/2, size/2, size/2);
    glVertex3f(size/2, -size/2, size/2);
    glVertex3f(size/2, -size/2, -size/2);

    //top face
    glColor3f(1, 0, 1);
    glVertex3f(size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, -size/2);
    glVertex3f(size/2, size/2, -size/2);
    
    //bottom face
    glColor3f(0, 1, 1);
    glVertex3f(size/2, -size/2, size/2);
    glVertex3f(-size/2, -size/2, size/2);
    glVertex3f(-size/2, -size/2, -size/2);
    glVertex3f(size/2, -size/2, size/2);
    glEnd();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 640/480, 1, 50);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -1);
    glRotatef(_angle, 0, 0, 1);
    glScalef(_scaleValue, _scaleValue, _scaleValue);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, 1, -5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, 0, -5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, 0, -5);
    glEnd();
    glFlush();
}

void update(int value)
{
    _angle += 0.5;
    _scaleValue += 0.1;
    if (_scaleValue > 2) {
        _scaleValue = 0.1;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char* argv[]) {
    
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Tutorial 1");
    init();
    glutDisplayFunc (display);
    glutIdleFunc(display);
    glutTimerFunc(25, update, 0);
    
    glutMainLoop ();
    
    return 0;
}