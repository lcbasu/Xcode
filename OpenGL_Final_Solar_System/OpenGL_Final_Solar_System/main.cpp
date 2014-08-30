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
#include "arcball/arcball.h"

using namespace std;

//Textures
GLuint sunTexture;
GLuint earthTexture;
GLuint moonTexture;

//Angles
GLfloat _angleSun = 0.0, _angleEarthRot = 0.0, _angleEarthRev = 0.0, _angleMoonRot = 0.0, _angleMoonRev = 0.0;


//Emission
GLfloat mat_emission[] = {1.0, 1.0, 0.0, 1.0};
GLfloat no_mat[] = {0, 0, 0, 0};
GLfloat light_pos[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lmodel_ambient[] = { 0.5, 0.5, 0.5, 1.0 };


//Arcball
static float aspect_ratio = 1.0f;
static int width, height;
const vec eye( 0.0f, 0.0f, -20.0f );
const vec centre( 0.0f, 0.0f, 0.0f );
const vec up( 0.0f, 1.0f, 0.0f );
const float SPHERE_RADIUS = 5.0f;

inline vec rotate_x( vec v, float sin_ang, float cos_ang )
{
	return vec(
               v.x,
               (v.y * cos_ang) + (v.z * sin_ang),
               (v.z * cos_ang) - (v.y * sin_ang)
               );
}

inline vec rotate_y( vec v, float sin_ang, float cos_ang )
{
	return vec(
               (v.x * cos_ang) + (v.z * sin_ang),
               v.y,
               (v.z * cos_ang) - (v.x * sin_ang)
               );
}

static void click_scene(int x, int y)
{
	int invert_y = (height - y) - 1;
	arcball_start(x,invert_y);
}

static void drag_scene(int x, int y)
{
	int invert_y = (height - y) - 1;
	arcball_move(x,invert_y);
}

static void mouse_button(int button, int state, int x, int y)
{
	if ( state == GLUT_DOWN )
        click_scene(x,y);
}

static void mouse_motion(int x, int y)
{
	drag_scene(x,y);
}

static void resize(int w, int h)
{
	width = w;
	height = h;
    aspect_ratio = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 15.0f, aspect_ratio, 1.0f, 50.0f );
    gluLookAt(
              eye.x, eye.y, eye.z,
              centre.x, centre.y, centre.z,
              up.x, up.y, up.z );
	// set up the arcball using the current projection matrix
	arcball_setzoom( SPHERE_RADIUS, eye, up );
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
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
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
    free( data );
    
    glBindTexture( GL_TEXTURE_2D, 0 );
    
    return texture;
}

void init()
{
    sunTexture = LoadTexture("/Users/LokeshBasu/Documents/Xcode/OpenGL_Final_Solar_System/OpenGL_Final_Solar_System/texture.bmp", 128, 128);
    earthTexture = LoadTexture("/Users/LokeshBasu/Documents/Xcode/OpenGL_Final_Solar_System/OpenGL_Final_Solar_System/girl.bmp", 128, 128);
    moonTexture = LoadTexture("/Users/LokeshBasu/Documents/Xcode/OpenGL_Final_Solar_System/OpenGL_Final_Solar_System/texture.bmp", 128, 128);
}

void display (void)
{
    glClearColor (0.0,0.0,0.0,1.0);

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
    arcball_rotate();
    
    //Sun
    glPushMatrix();
    
    //Sun Texture
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj = gluNewQuadric();
    gluQuadricNormals(qObj, GLU_SMOOTH);
    gluQuadricTexture(qObj, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sunTexture);
    
    //Sun rotation
    glRotatef(_angleSun, 0.0, 1.0, 0.0);
    
    //Sunlight
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.5, 0.5, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    glShadeModel (GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    
    //Emission
    GLfloat emission[4] = {1.0, 1.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
    
    //Draw Sun
    gluSphere(qObj, 1.0f, 24, 240);
    
    //Reset the emission back to default
    GLfloat r_emission[4] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, r_emission);
    
    //Earth
    glPushMatrix();
    
    //Reverse the rotation of the sun from the earth axis
    glRotatef(-_angleSun, 0.0, 1.0, 0.0);
    
    //Earth texture
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj2 = gluNewQuadric();
    gluQuadricNormals(qObj2, GLU_SMOOTH);
    gluQuadricTexture(qObj2, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, earthTexture);
    
    //Earth revolution
    glRotatef(_angleEarthRev, 0.0, 1.0, 0.0);
    glTranslatef(3.0, 0.0, 0.0);
    
    //Earth rotation
    glRotatef(_angleEarthRot, 0.0, 1.0, 0.0);
    
    //Draw Earth
    gluSphere(qObj2, 0.6f, 24, 24);
    
    //Moon
    glPushMatrix();
    
    //Reverse the rotation of the earth from the earth axis
    glRotatef(-_angleEarthRot, 0.0, 1.0, 0.0);
    
    //Moon texture
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj3 = gluNewQuadric();
    gluQuadricNormals(qObj3, GLU_SMOOTH);
    gluQuadricTexture(qObj3, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, moonTexture);
    
    //Moon revolution
    glRotatef(_angleMoonRev, 0.0, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    //Moon rotation
    glRotatef(_angleMoonRot, 0.0, 1.0, 0.0);
    
    //Draw Moom
    gluSphere(qObj3, 0.3f, 24, 24);
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
    _angleMoonRev += 6.0f;
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

void FreeTexture(GLuint texture)
{
    glDeleteTextures( 1, &texture );
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize (900, 600);
    glutInitWindowPosition (200, 100);
    glutCreateWindow ("Texture");
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (resize);
    
    init();
    
    glutTimerFunc(25, update, 0);
    
    glutMouseFunc(mouse_button);
    glutMotionFunc(mouse_motion);
    
    glutMainLoop ();
    
    FreeTexture(sunTexture);
    FreeTexture(earthTexture);
    FreeTexture(moonTexture);
    
    return 0;
}