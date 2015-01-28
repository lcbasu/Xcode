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
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <math.h>

#include "glm.hpp"
#include "matrix_transform.hpp"
#include "quaternion.hpp"
#include "type_ptr.hpp"

float _angle = 0;
float _scaleValue = 0.1;
GLuint brickTexture;

//float pos[] = {-2, 2.0, -3, 1};
//float dif[] = {1, 1, 1, 1};
//float amb[] = {0.1, 0.1, 0.1, 1};
//float spe[] = {1, 1, 1, 1};

struct coordinate {
    float x, y, z;
    coordinate(float a, float b, float c) x(a), y(b), z(c) {};
};





//void drawCube(float size)
//{
//    //material diffuse and ambient color
//    float difamb[] = {1, 0.5, 0.3, 1};
//    glBegin(GL_QUADS);
//    //applying material to front and back side
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difamb);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, difamb);
//    //front face
//    glNormal3f(0, 0, 1);
//    glVertex3f(size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, size/2);
//    glVertex3f(-size/2, -size/2, size/2);
//    glVertex3f(size/2, -size/2, size/2);
//    
//    //left face
//    glNormal3f(-1, 0, 0);
//    glVertex3f(-size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, -size/2);
//    glVertex3f(-size/2, -size/2, -size/2);
//    glVertex3f(-size/2, -size/2, size/2);
//    
//    //back face
//    glNormal3f(0, 0, -1);
//    glVertex3f(size/2, size/2, -size/2);
//    glVertex3f(-size/2, size/2, -size/2);
//    glVertex3f(-size/2, -size/2, -size/2);
//    glVertex3f(size/2, -size/2, -size/2);
//    
//    //right face
//    glNormal3f(1, 0, 0);
//    glVertex3f(size/2, size/2, -size/2);
//    glVertex3f(size/2, size/2, size/2);
//    glVertex3f(size/2, -size/2, size/2);
//    glVertex3f(size/2, -size/2, -size/2);
//
//    //top face
//    glNormal3f(0, 1, 0);
//    glVertex3f(size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, size/2);
//    glVertex3f(-size/2, size/2, -size/2);
//    glVertex3f(size/2, size/2, -size/2);
//    
//    //bottom face
//    glNormal3f(0, -1, 0);
//    glVertex3f(size/2, -size/2, size/2);
//    glVertex3f(-size/2, -size/2, size/2);
//    glVertex3f(-size/2, -size/2, -size/2);
//    glVertex3f(size/2, -size/2, -size/2);
//    glEnd();
//}

int loadObject(const char* fileName)
{
    return 0;
}

//function to load the RAW file
GLuint LoadTexture(const char * filename, int width, int height)
{
    GLuint texture;
    unsigned char * data;
    FILE * file;
    
    file = fopen( filename, "r");
    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );
    
    glGenTextures( 1, &texture);
    glBindTexture( GL_TEXTURE_2D, texture);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
    
    free( data );
    
    glBindTexture( GL_TEXTURE_2D, 0 );
    
    return texture;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 640/480, 1, 50);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    const char * filename = "/Users/LokeshBasu/Documents/Xcode/OpenGLProgramming/OpenGLProgramming/brickwork-texture_opengl.bmp";
    brickTexture = LoadTexture(filename, 512, 512);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
//    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glTranslatef(0, 0, -5);
    glRotatef(_angle, 1, 1, 1);
//    glScalef(_scaleValue, _scaleValue, _scaleValue);
//    drawCube(1);
    
    
    glBindTexture(GL_TEXTURE_2D, brickTexture);
    glBegin(GL_QUADS);
    glVertex3f(-1, 1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-1, -1, 0);
    glTexCoord2f(0, 3);
    glVertex3f(1, -1, 0);
    glTexCoord2f(3, 3);
    glVertex3f(1, 1, 0);
    glTexCoord2f(3, 0);
    glEnd();
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