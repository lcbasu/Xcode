//
//  main.cpp
//  OpenGL_Ch_1
//
//  Created by Lokesh Basu on 22/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>

void dispaly()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(0.7f, 0.5f, 0.0f);
    glVertex3f(0.7f, 0.7f, 0.0f);
    glVertex3f(0.5f, 0.7f, 0.0f);
    glEnd();
    
    glFlush();
}

void init()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chapter 1 Example 1");
    init();
    glutDisplayFunc(dispaly);
    glutMainLoop();
    return 0;
}