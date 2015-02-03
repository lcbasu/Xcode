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

using namespace std;


struct coordinate {
    float x, y, z;
    coordinate(float a, float b, float c) : x(a), y(b), z(c) {};
};


struct face {
    int faceNum;
    bool four;  //whether it is a quad or triangle
    int faces[4];   //3 for triangle, 4 for quads
    face(int faceN, int f1, int f2, int f3, int f4) : faceNum(faceN) {
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        faces[3] = f4;
        four = true;
    }
};


int loadObject(const char* fileName)
{
    vector<string *> objectCoords;
    vector<coordinate *> vertex;
    vector<face *> faces;
    vector<coordinate *> normal;
    
    ifstream in(fileName);
    
    if (!in.is_open()) {
        cout << "File not open!" << endl;
        return -1;
    }
    
    char buf[256];
    while (!in.eof()) {
        in.getline(buf, 256);
        objectCoords.push_back(new string(buf));
    }
    
    for (int i = 0; i < objectCoords.size(); i++) {
        if (*objectCoords[i][0] == '#') {
            continue;
        } else if (*objectCoords[i][0] == 'v' && *objectCoords[i][1] == ' ') {
            float tmpX, tmpY, tmpZ;
            sscanf(objectCoords[i]->c_str(), "v %f %f %f", &tmpX, &tmpY, &tmpZ);
            vertex.push_back(new coordinate(tmpX, tmpY, tmpZ));
        } else if (*objectCoords[i][0] == 'v' && *objectCoords[i][1] == 'n') {
            float tmpX, tmpY, tmpZ;
            sscanf(objectCoords[i]->c_str(), "vn %f %f %f", &tmpX, &tmpY, &tmpZ);
            normal.push_back(new coordinate(tmpX, tmpY, tmpZ));
        } else if (*objectCoords[i][0] == 'f') {
            int a, b, c, d, e;
            //if a quad else a traingle
            if (count(objectCoords[i]->begin(), objectCoords[i]->end(), ' ') == 4) {
                sscanf(objectCoords[i]->c_str(), "f %d//%d %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b, &e, &b);
                faces.push_back(new face(b, a, c, d, e));
            } else {
                sscanf(objectCoords[i]->c_str(), "f %d//%d %d//%d %d//%d", &a, &b, &c, &b, &d, &b);
                faces.push_back(new face(b, a, c, d));
            }
        }
    }
    
    //to draw
    int num;
    num = glGenLists(1);
    
    glNewList(num, GL_COMPILE);
    
    for (int i = 0; i < faces.size(); i++) {
        if (faces[i]->four) {
            //draw quad
            glBegin(GL_QUADS);
            glNormal3f(normal[faces[i]->faceNum - 1]->x, normal[faces[i]->faceNum - 1]->y, normal[faces[i]->faceNum - 1]->z);
            glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[3] - 1]->x, vertex[faces[i]->faces[3] - 1]->y, vertex[faces[i]->faces[3] - 1]->z);
            glEnd();
            
        } else {
            //draw triangle
            glBegin(GL_TRIANGLES);
            glNormal3f(normal[faces[i]->faceNum - 1]->x, normal[faces[i]->faceNum - 1]->y, normal[faces[i]->faceNum - 1]->z);
            glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
            glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
            glEnd();
        }
    }
    
    glEndList();
    
    //avoids memory leak
    for (int i = 0; i < objectCoords.size(); i++) {
        delete objectCoords[i];
    }

    for (int i = 0; i < faces.size(); i++) {
        delete faces[i];
    }

    for (int i = 0; i < normal.size(); i++) {
        delete normal[i];
    }
    
    for (int i = 0; i < vertex.size(); i++) {
        delete vertex[i];
    }
    return num;
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
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


int main(int argc, char* argv[])
{
    
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Tutorial 1");
    init();
    glutDisplayFunc (display);
    glutIdleFunc(display);
    glutMainLoop ();
    
    return 0;
}