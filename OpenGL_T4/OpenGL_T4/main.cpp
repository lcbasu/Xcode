//
//  main.cpp
//  OpenGL_T4
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
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);      //enable lighting
    glEnable(GL_LIGHT0);        //enable light #0
    glEnable(GL_LIGHT1);        //enable light #1
    glEnable(GL_NORMALIZE);     //automatically normalize normals
    glShadeModel(GL_SMOOTH);    //enable smooth shading
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

float _angle = -70.0f;

// drwas the 3D scene
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -8.0f);
    
    //add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    
    //add positioned light
    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //position at (4,0,8)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    
    //add directed light
    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //color (0.5,0.2,0.2)
    //coming from direction (-1,0.5,0.5)
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    
    glBegin(GL_QUADS);
    
    //front
    //glNormal3f(0.0f, 0.0f, 1.0f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, -1.0f, 1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, 1.0f, 1.5f);
    
    //right
    //glNormal3f(1.0f, 0.0f, 0.0f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, -1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, 1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, -1.0f, 1.5f);
    
    //back
    //glNormal3f(0.0f, 0.0f, -1.0f);
    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, -1.0f, -1.5f);
    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, 1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, 1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, -1.0f, -1.5f);
    
    //left
    //glNormal3f(-1.0f, 0.0f, 0.0f);
    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, -1.0f, -1.5f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, 1.0f, 1.5f);
    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, 1.0f, -1.5f);
    
    glEnd();
    glutSwapBuffers();
    
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

int main(int argc, char * argv[])
{
    // initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400); // set the window size
    
    // create the window
    glutCreateWindow("Lighting");
    initRendering(); // initialize rendering
    
    // set handler function for drawing, keypress and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyPress);
    glutReshapeFunc(handleResize);
    
    glutTimerFunc(25, update, 0);
    glutMainLoop(); // start the main loop. glutMainLoop doesn't return.
    return 0;
}

