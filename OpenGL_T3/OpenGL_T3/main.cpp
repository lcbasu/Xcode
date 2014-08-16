//
//  main.cpp
//  OpenGL_T3
//
//  Created by Lokesh Basu on 16/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void handleKeyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(0);
    }
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL); //enable colour
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
}

// called when window is resized
void handleResize(int w, int h)
{
    // tells opengl how to convert form coordinates to pixel values
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //switch to setting the camera perspective
    
    // setting the camera perspective
    glLoadIdentity(); // reset the camera
    gluPerspective(45.0                     // the camera angle
                   , (double)w/(double)h    // the width to height ratio
                   , 1                      // the near z clipping co-ordinate
                   , 200);                  // the far z clipping co-ordinate
}

float _angle = 30.0f;
float _cameraAngle = 10.0f;

// drwas the 3D scene
void drawScene()
{
    // clear information from the last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW); // switch to the drawing perspectve
    glLoadIdentity();
    glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    
    
    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 0.0f, 1.0f);
    

    glBegin(GL_QUADS); // begin quadrilateral co-ordinates

    // trapezoid
    glColor3f(0.5f, 0.0f, 0.8f);
    glVertex3f(-0.7f, -0.5f, 0.0f);
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex3f(0.7f, -0.5f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.4f, 0.5f, 0.0f);
    glColor3f(0.0f, 0.65f, 0.65f);
    glVertex3f(-0.4f, 0.5f, 0.0f);
    
    glEnd(); // end quadrilateral co-ordinates
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glScalef(0.7f, 0.7f, 0.7f);
    
    glBegin(GL_TRIANGLES); // begin triangle co-ordinates
    glColor3f(0.0f, 0.75f, 0.0f);
    
    // pentagon
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    
    glEnd();
    glPopMatrix();
    
    glTranslatef(-1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 1.0f, 2.0f, 3.0f);
    
    glBegin(GL_TRIANGLES);
    
    // triangle
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    
    glEnd(); // end trianle co-ordinates
    
    glutSwapBuffers(); // send the 3d scene to the screen
    
}

void update(int value)
{
    _angle += 2.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
    // initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400); // set the window size
    
    // create the window
    glutCreateWindow("Shapes");
    initRendering(); // initialize rendering
    
    // set handler function for drawing, keypress and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(handleResize);
    
    glutTimerFunc(25, update, 0);
    glutMainLoop(); // start the main loop. glutMainLoop doesn't return.
    return 0;
}

