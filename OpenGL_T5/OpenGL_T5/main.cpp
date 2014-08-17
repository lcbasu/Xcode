//
//  main.cpp
//  OpenGL_T5
//
//  Created by Lokesh Basu on 17/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>
#include "imageloader.h"

using namespace std;

void handleKeyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(0);
    }
}

GLuint loadTexture(Image *image)
{
    GLuint textureId;
    glGenTextures(1, &textureId); //make room for our texture
    glBindTexture(GL_TEXTURE_2D, textureId); //tell OpenGL which texture to edit
    //map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,         //always GL_TEXTURE_2D
                 0,                     //0 for now
                 GL_RGB,                //format OpenGL uses for image
                 image->width,          //width
                 image->height,         //height
                 0,                     //the border of the image
                 GL_RGB,                //GL_RGB because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE,      //GL_UNSIGNED_BYTE because pixels are stored as unsigned numbers
                 image->pixels);        //the actual pixel data
    
    
    return textureId; //return the id of the texture
}

GLuint _textureId; //The id of the texture

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);      //enable lighting
    glEnable(GL_LIGHT0);        //enable light #0
    glEnable(GL_NORMALIZE);     //automatically normalize normals
    
    Image *image = loadBMP("splash.bmp");
    _textureId = loadTexture(image);
    delete image;
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
    
    GLfloat directedLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
    glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    
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

