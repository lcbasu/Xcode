//
//  main.cpp
//  OpenGL_Final_Solar_System
//
//  Created by Lokesh Basu on 28/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

GLuint testTexture; //the array for our texture

GLfloat angle = 0.0;

GLfloat _angleSun = 0.0, _angleEarthRot = 0.0, _angleEarthRev = 0.0, _angleMoonRot = 0.0, _angleMoonRev = 0.0;

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
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
    free( data );
    
    glBindTexture( GL_TEXTURE_2D, 0 );
    
    return texture;
}

void display (void)
{
    
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    
    
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0.0f, 0.0f, -3.0f );
    
    glPushMatrix();
    
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj = gluNewQuadric();
    gluQuadricNormals(qObj, GLU_SMOOTH);
    gluQuadricTexture(qObj, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, testTexture);
    
    glRotatef(_angleSun, 0.0, 1.0, 0.0);
    gluSphere(qObj, 1.0f, 24, 24);
    
    
    //Earth
    glPushMatrix();
    
    glRotatef(-_angleSun, 0.0, 1.0, 0.0);
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj2 = gluNewQuadric();
    gluQuadricNormals(qObj2, GLU_SMOOTH);
    gluQuadricTexture(qObj2, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, testTexture);
    
    glRotatef(_angleEarthRev, 0.0, 0.0, 1.0);
    glTranslatef(3.0, 0.0, 0.0);
    glRotatef(_angleEarthRot, 0.0, 1.0, 0.0);

    gluSphere(qObj2, 0.5f, 24, 24);
    
    
    //Moon
    glPushMatrix();
    
    glRotatef(-_angleEarthRot, 0.0, 1.0, 0.0);
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj3 = gluNewQuadric();
    gluQuadricNormals(qObj3, GLU_SMOOTH);
    gluQuadricTexture(qObj3, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, testTexture);
    
    glRotatef(_angleMoonRev, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(_angleMoonRot, 0.0, 0.0, 1.0);
    
    //glRotatef(_angleEarthRot, 0.0, 1.0, 0.0);
    
    
    gluSphere(qObj3, 0.25f, 24, 24);
    
    glPopMatrix();
    
    
    glPopMatrix();
    
    glPopMatrix();
    
    glutSwapBuffers();
}

void update(int value)
{
    _angleSun += 0.1f;
    _angleEarthRot += 1.0f;
    _angleEarthRev += 0.8f;
    _angleMoonRot += 0.6f;
    _angleMoonRev += 0.4f;
    if (_angleSun > 360) {
        _angleSun -= 360;
    }
    if (_angleEarthRev > 360) {
        _angleEarthRev -= 360;
    }
    if (_angleEarthRot > 360) {
        _angleEarthRot -= 360;
    }
    if (_angleMoonRev > 360) {
        _angleMoonRev -= 360;
    }
    if (_angleMoonRot > 360) {
        _angleMoonRot -= 360;
    }
    if (_angleMoonRev > 360) {
        _angleMoonRev -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}


void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0)
    ;
    glMatrixMode (GL_MODELVIEW);
}

void FreeTexture( GLuint texture )
{
    glDeleteTextures( 1, &texture );
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Texture");
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
    
    testTexture = LoadTexture("/Users/LokeshBasu/Documents/Xcode/OpenGL_Final_Solar_System/OpenGL_Final_Solar_System/texture.bmp", 256, 256);
    
    
    glutTimerFunc(25, update, 0);
    glutMainLoop ();
    
    FreeTexture(testTexture);
    
    return 0;
}
