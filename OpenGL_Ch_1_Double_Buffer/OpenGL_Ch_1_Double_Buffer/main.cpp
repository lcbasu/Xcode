//
//  main.cpp
//  OpenGL_Ch_1_Double_Buffer
//
//  Created by Lokesh Basu on 24/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

static GLfloat _angle = 0.0f;

void init()
{
    glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
}

void dispaly()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(_angle, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.2f, -0.2f, 0.2f, 0.2f);
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay()
{
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(800, 100);
    glutCreateWindow("Double Buffering");
    init();
    glutDisplayFunc(dispaly);
    glutIdleFunc(spinDisplay);
    glutMainLoop();
    return 0;
}
