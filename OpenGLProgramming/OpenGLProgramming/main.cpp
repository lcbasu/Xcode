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

float pos[] = {-2, 2.0, -3, 1};
float dif[] = {1, 1, 1, 1};
float amb[] = {0.1, 0.1, 0.1, 1};
float spe[] = {1, 1, 1, 1};

void drawCube(float size)
{
    glBegin(GL_QUADS);
    //front face
    glNormal3f(0, 0, 1);
    glColor3f(1, 0, 0);
    glVertex3f(size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, size/2);
    glVertex3f(-size/2, -size/2, size/2);
    glVertex3f(size/2, -size/2, size/2);
    
    //left face
    glNormal3f(-1, 0, 0);
    glColor3f(0, 1, 0);
    glVertex3f(-size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, -size/2);
    glVertex3f(-size/2, -size/2, -size/2);
    glVertex3f(-size/2, -size/2, size/2);
    
    //back face
    glNormal3f(0, 0, -1);
    glColor3f(0, 0, 1);
    glVertex3f(size/2, size/2, -size/2);
    glVertex3f(-size/2, size/2, -size/2);
    glVertex3f(-size/2, -size/2, -size/2);
    glVertex3f(size/2, -size/2, -size/2);
    
    //right face
    glNormal3f(1, 0, 0);
    glColor3f(1, 1, 0);
    glVertex3f(size/2, size/2, -size/2);
    glVertex3f(size/2, size/2, size/2);
    glVertex3f(size/2, -size/2, size/2);
    glVertex3f(size/2, -size/2, -size/2);

    //top face
    glNormal3f(0, 1, 0);
    glColor3f(1, 0, 1);
    glVertex3f(size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, size/2);
    glVertex3f(-size/2, size/2, -size/2);
    glVertex3f(size/2, size/2, -size/2);
    
    //bottom face
    glNormal3f(0, -1, 0);
    glColor3f(0, 1, 1);
    glVertex3f(size/2, -size/2, size/2);
    glVertex3f(-size/2, -size/2, size/2);
    glVertex3f(-size/2, -size/2, -size/2);
    glVertex3f(size/2, -size/2, -size/2);
    glEnd();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 640/480, 1, 50);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glTranslatef(0, 0, -5);
    glRotatef(_angle, 1, 1, 1);
//    glScalef(_scaleValue, _scaleValue, _scaleValue);
    drawCube(1);
    glFlush();
}

void update(int value)
{
    _angle += 0.5;
    _scaleValue += 0.1;
    if (_scaleValue > 2) {
        _scaleValue = 0.1;
    }
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char* argv[]) {
    
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
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