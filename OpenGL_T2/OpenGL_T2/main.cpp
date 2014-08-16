//
//  main.cpp
//  OpenGL_T2
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

// drwas the 3D scene
void drawScene()
{
    // clear information from the last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW); // switch to the drawing perspectve
    glLoadIdentity();
    
    glBegin(GL_QUADS); // begin quadrilateral co-ordinates
    
    // trapezoid
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.7f, -1.5f, -5.0f);
    glVertex3f(0.4f, -0.5f, -5.0f);
    glVertex3f(-0.4f, -0.5f, -5.0f);
    
    glEnd(); // end quadrilateral co-ordinates
    
    
    glBegin(GL_TRIANGLES); // begin triangle co-ordinates
    
    // pentagon
    glVertex3f(0.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 0.5f, -5.0f);
    glVertex3f(0.5f, 1.0f, -5.0f);
    
    glVertex3f(0.5f, 1.0f, -5.0f);
    glVertex3f(1.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 1.0f, -5.0f);
    
    glVertex3f(0.5f, 1.0f, -5.0f);
    glVertex3f(1.5f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.5f, -5.0f);
    
    // triangle
    
    glVertex3f(-0.5f, 0.5f, -5.0f);
    glVertex3f(-1.0f, 1.5f, -5.0f);
    glVertex3f(-1.5f, 0.5f, -5.0f);
    
    glEnd(); // end trianle co-ordinates
    
    glutSwapBuffers(); // send the 3d scene to the screen
    
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
    
    glutMainLoop(); // start the main loop. glutMainLoop doesn't return.
    return 0;
}

