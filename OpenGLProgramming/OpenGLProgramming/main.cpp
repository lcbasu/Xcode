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


void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 640/480, 1, 50);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, 1, -5);
    glVertex3f(0.5, 0, -5);
    glVertex3f(-0.5, 0, -5);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Tutorial 1");
    init();
    glutDisplayFunc (display);
    
    glutMainLoop ();
    
    return 0;
}