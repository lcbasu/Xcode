//
//  main.cpp
//  OpenGL
//
//  Created by Lokesh Basu on 16/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//


#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// This is just an example using basic glut functionality.
// If you want specific Apple functionality, look up AGL

void init() // Called before main loop to set up the program
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

// Called at the start of the program, after a glutPostRedisplay() and during idle
// to display a frame
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0, 0.0, -10.0);
        glVertex3f(1.0, 0.0, -10.0);
        glVertex3f(0.0, 1.0, -10.0);
    glEnd();
    
    glutSwapBuffers();
}

// Called every time a window is resized to resize the projection matrix
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initializes glut
    
    // Sets up a double buffer with RGBA components and a depth component
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    
    // Sets the window size to 512*512 square pixels
    glutInitWindowSize(512, 512);
    
    // Sets the window position to the upper left
    glutInitWindowPosition(0, 0);
    
    // Creates a window using internal glut functionality
    glutCreateWindow("Hello!");
    
    // passes reshape and display functions to the OpenGL machine for callback
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    init();
    
    // Starts the program.
    glutMainLoop();
    return 0;
}