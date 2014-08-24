//
//  main.cpp
//  OpenGL_Ch_2_Ex_1
//
//  Created by Lokesh Basu on 24/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

void init()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glutSolidTorus(0.1f, 0.5f, 10.0f, 200.0f);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(600, 100);
    glutCreateWindow("Solid Torus");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}