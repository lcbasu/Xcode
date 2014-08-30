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


void init()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    
    glShadeModel (GL_SMOOTH);
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}




/*

struct Material
{
    Material( color4 ambient = color4(0.2, 0.2, 0.2, 1.0)
             , color4 diffuse = color4(0.8, 0.8, 0.8, 1.0)
             , color4 specular = color4(0.0, 0.0, 0.0, 1.0)
             , color4 emission = color4(0.0, 0.0, 0.0, 1.0)
             , float shininess = 0 )
    : m_Ambient( ambient )
    , m_Diffuse( diffuse )
    , m_Specular( specular )
    , m_Emission( emission )
    , m_Shininess( shininess )
    {}
    
    void Apply()
    {
        glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, &(m_Ambient.r) );
        glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, &(m_Diffuse.r) );
        glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, &(m_Specular.r) );
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, &(m_Emission.r) );
        glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, m_Shininess );
    }
    
    color4 m_Ambient;
    color4 m_Diffuse;
    color4 m_Specular;
    color4 m_Emission;
    float  m_Shininess;
    
};

struct Light
{
    Light( GLenum lightID = GL_LIGHT0
          , color4 ambient = color4( 0.0, 0.0, 0.0, 1.0 )
          , color4 diffuse = color4( 1.0, 1.0, 1.0, 1.0 )
          , color4 specular = color4( 1.0, 1.0, 1.0, 1.0 )
          , float4 position = float4( 0.0, 0.0, 1.0, 0.0 )
          , float3 spotDirection = float3( 0.0, 0.0, 1.0 )
          , float  spotExponent = 0.0
          , float  spotCutoff = 180.0f
          , float  constantAttenuation = 1.0
          , float  linearAttenuation = 0.0
          , float  quadraticAttenuation = 0.0 )
    : m_LightID ( lightID )
    , m_Ambient( ambient )
    , m_Diffuse( diffuse )
    , m_Specular( specular )
    , m_Position( position )
    , m_SpotDirection( spotDirection )
    , m_SpotExponent( spotExponent )
    , m_SpotCutoff( spotCutoff )
    , m_ConstantAttenuation( constantAttenuation )
    , m_LinearAttenuation( linearAttenuation )
    , m_QuadraticAttenuation( quadraticAttenuation )
    {}
    
    void Activate()
    {
        glEnable( m_LightID );
        glLightfv( m_LightID, GL_AMBIENT, &(m_Ambient.r) );
        glLightfv( m_LightID, GL_DIFFUSE, &(m_Diffuse.r) );
        glLightfv( m_LightID, GL_SPECULAR, &(m_Specular.r) );
        glLightfv( m_LightID, GL_POSITION, &(m_Position.x) );
        glLightfv( m_LightID, GL_SPOT_DIRECTION, &(m_SpotDirection.x) );
        glLightf( m_LightID, GL_SPOT_EXPONENT, m_SpotExponent );
        glLightf( m_LightID, GL_SPOT_CUTOFF, m_SpotCutoff );
        glLightf( m_LightID, GL_CONSTANT_ATTENUATION, m_ConstantAttenuation );
        glLightf( m_LightID, GL_LINEAR_ATTENUATION, m_LinearAttenuation );
        glLightf( m_LightID, GL_QUADRATIC_ATTENUATION, m_QuadraticAttenuation );
    }
    
    void Deactivate()
    {
        glDisable( m_LightID );
    }
    
    GLenum m_LightID;
    GLfloat m_Ambient[4] = {0.0, 0.0, 0.0, 1.0};
    GLfloat m_Diffuse[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat m_Specular[4] = {1.0, 1.0, 1.0, 1.0};
    
    GLfloat m_Position[4] = {0.0, 0.0, 1.0, 0.0};
    GLfloat m_SpotDirection[3] = {0.0, 0.0, 1.0};
    
    float  m_SpotExponent = 0.0;
    float  m_SpotCutoff = 180.0f;
    float  m_ConstantAttenuation = 1.0;
    float  m_LinearAttenuation = 0.0;
    float  m_QuadraticAttenuation = 0.0;
};

*/

void display (void)
{
    
    glClearColor (1.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    
    
    
    
    //Sunlight
    //Light g_SunLight( GL_LIGHT0, color4(0,0,0,1), color4(1,1,1,1), color4(1,1,1,1), float4(0,0,0,1) );
    
    // Material properties
    //Material g_SunMaterial( color4(0,0,0,1), color4(1,1,1,1), color4(1,1,1,1) );
    //Material g_EarthMaterial( color4( 0.2, 0.2, 0.2, 1.0), color4( 1, 1, 1, 1), color4( 1, 1, 1, 1), color4(0, 0, 0, 1), 50 );
    //Material g_MoonMaterial( color4( 0.1, 0.1, 0.1, 1.0), color4( 1, 1, 1, 1), color4( 0.2, 0.2, 0.2, 1), color4(0, 0, 0, 1), 10 );
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //glTranslatef( 0.0f, 0.0f, -3.0f );
    
    glPushMatrix();
    
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glEnable( GL_TEXTURE_2D );
    GLUquadricObj *qObj = gluNewQuadric();
    gluQuadricNormals(qObj, GLU_SMOOTH);
    gluQuadricTexture(qObj, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, testTexture);
    
    glRotatef(_angleSun, 0.0, 1.0, 0.0);
    
    //g_SunLight.Activate();
    
    //Sunlight
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.5, 0.5, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    glShadeModel (GL_SMOOTH);
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    
    //Draw Sun
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
    
    glRotatef(_angleEarthRev, 0.0, 1.0, 0.0);
    glTranslatef(3.0, 0.0, 0.0);
    glRotatef(_angleEarthRot, 0.0, 1.0, 0.0);
    
    
    

    //g_EarthMaterial.Apply();

    
    //Draw Earth
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
    
    glRotatef(_angleMoonRev, 0.0, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(_angleMoonRot, 0.0, 1.0, 0.0);
    
    //g_MoonMaterial.Apply();

    
    //Draw Moom
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
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

void FreeTexture( GLuint texture )
{
    glDeleteTextures( 1, &texture );
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Texture");
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
    
    testTexture = LoadTexture("/Users/LokeshBasu/Documents/Xcode/OpenGL_Final_Solar_System/OpenGL_Final_Solar_System/texture.bmp", 128, 128);
    
    
    glutTimerFunc(25, update, 0);
    glutMainLoop ();
    
    FreeTexture(testTexture);
    
    return 0;
}
