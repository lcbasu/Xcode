//
//  main.cpp
//  OpenGL_Ch3_Solar_System
//
//  Created by Lokesh Basu on 18/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>


using namespace std;



#define pi 3.14159265358979323846
using namespace std;
#define SunSize 0.2
#define MarcurySize 0.016
#define VenusSize 0.03
#define EarthSize 0.035
#define MarsSize 0.037
#define JupiterSize 0.09
#define SaturnSize 0.07
#define UranusSize 0.045
#define NeptuneSize 0.04

GLfloat xRot, yRot, zRot,x=-1.0,y,z;

GLfloat SpeedX = 0.5;
GLfloat year = 0.0; //degrees
GLfloat day = 0.0;
GLfloat moonAroundEarth = 0.0;
GLfloat moonItsSelf = 0.0;
GLfloat EarthOrbitRadius = 1.0;
GLfloat MoonOrbitRadius = 0.1;
GLfloat daySpeed = 2.0 * SpeedX;
GLfloat DaysPerYear =360;
GLfloat yearSpeed = DaysPerYear / 360.0 * daySpeed * SpeedX;
GLfloat moonAroundEarthSpeed = 1 * SpeedX;
GLfloat moonItsSelfSpeed = .5 * SpeedX;
typedef struct Planet
{
    GLfloat DaysPerYear,OrbitR,Size;
    GLfloat Clx,Cly,Clz;
    GLfloat yearSpeed ,day,year;
    
} Planet;
Planet Marcury={88,0.3,MarcurySize,
    0.8,0.8,0.0 //color
    ,0.0,0.0,0.0};
Planet Venus={224,0.4,VenusSize,
    0.9,0.4,0.0 //color
    ,0.0,0.0,0.0};
Planet Earth={365,0.7,EarthSize,
    0.0,0.5,0.6
    ,0.0,0.0,0.0};
Planet Mars ={686,0.9,MarsSize,
    0.8,0.2,0.2,   //color
    0.0 , 0.0 , 0.0};
Planet Jupiter={3960,1.3,JupiterSize,
    0.8,0.1,0.6,
    0.0,0.0,0.0
};
Planet Uranus ={10000,2.0,UranusSize,
    0.0,0.8,0.8,   //color
    0.0 , 0.0 , 0.0};
Planet Neptune ={30000,2.3,NeptuneSize,
    0.2,0.2,0.9,   //color
    0.0 , 0.0 , 0.0};
void SpeedGen()
{
    Marcury.yearSpeed=Marcury.DaysPerYear / 360.0 * daySpeed*12.0 * SpeedX;
    Venus.yearSpeed= Venus.DaysPerYear / 360.0 * daySpeed *2.0* SpeedX;
    Earth.yearSpeed=Earth.DaysPerYear / 360.0 * daySpeed * SpeedX;
    Mars.yearSpeed= Mars.DaysPerYear / 360.0 * daySpeed *0.5* SpeedX;
    Jupiter.yearSpeed= Mars.DaysPerYear / 360.0 * daySpeed *0.4* SpeedX;
    Uranus.yearSpeed= Uranus.DaysPerYear / 360.0 * daySpeed *0.01* SpeedX;
    Neptune.yearSpeed= Neptune.DaysPerYear / 360.0 * daySpeed *0.009* SpeedX;
}


void PlacePlanet(Planet x)
{
    glRotatef(x.year,0.2,1.0,0.1);
    glTranslatef(x.OrbitR,0.0,0.0);
    glRotatef(-(x.year),0.2,1.0,0.1);
    glPushMatrix();
    glRotatef(x.day,0.25,1.0,0.0);
    glColor3f(x.Clx,x.Cly,x.Clz);
    glutWireSphere(x.Size,20,20);  //Draw earth
    //Draw earth rotation axis
    
    glPopMatrix();
}

void RenderScene()
{
    glPushMatrix();
    gluLookAt( 0.0,0.0, -4.0,
              0.0 ,0.0 ,1.0,
              0.0 , -3.0, 0.0);
    
    glColor3f(1.0,1.0,0.6);
    glutWireSphere(SunSize,50,50);
    glPushMatrix();
    glPushMatrix();
    PlacePlanet(Marcury);
    glPopMatrix();
    glPushMatrix();
    PlacePlanet(Venus);
    glPopMatrix();
    glPushMatrix();
    PlacePlanet(Earth);
    glPopMatrix();
    glPushMatrix();
    PlacePlanet(Mars);
    glPopMatrix();
    glPushMatrix();
    PlacePlanet(Jupiter);
    glPopMatrix();
    glPushMatrix();
    PlacePlanet(Uranus);
    glPopMatrix();
    glPushMatrix();
    PlacePlanet(Neptune);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //glutSwapBuffers();
    
    
}
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    RenderScene();
    glFlush();
    glutSwapBuffers();
    
}

void Reshape(int x,int y)
{
    if(y==0 ) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
    Display();
    
}

void Idle()
{
    Marcury.day += daySpeed;
    Marcury.year += Marcury.yearSpeed;
    
    Venus.day += daySpeed;
    Venus.year += Venus.yearSpeed;
    
    Mars.day += daySpeed;
    Mars.year += Mars.yearSpeed;
    
    Earth.day += daySpeed;
    Earth.year += Earth.yearSpeed;
    
    Jupiter.day += daySpeed;
    Jupiter.year += Jupiter.yearSpeed;
    
    Uranus.day += daySpeed;
    Uranus.year += Uranus.yearSpeed;
    
    Neptune.day += daySpeed;
    Neptune.year += Neptune.yearSpeed;
    
    Display();
    
}
void Init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClearDepth(30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    SpeedGen();
    cout<<Venus.yearSpeed<<endl;
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // double buffering for Animation
    glutInitWindowSize(1024,768);
    // Creating a Window with rendring
    glutCreateWindow("Soler System");
    //Functions
    Init();
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);
    glutMainLoop();
    
    return 0;
}