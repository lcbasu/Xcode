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

using namespace std;

char fs[] = "varying vec3 f_color;"
"void main(void) {"
    "gl_FragColor = vec4(f_color.x, f_color.y, f_color.z, 1.0);"
"}";
char vs[] = "attribute vec2 coord2d;"
"attribute vec3 v_color;"
"varying vec3 f_color;"
"void main(void) {"
    "gl_Position = vec4(coord2d, 0.0, 1.0);"
    "f_color = v_color;"
"}";

void onDisplay()
{
    /* Clear the background as white */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_3_2_CORE_PROFILE);
    
    glutInitWindowSize(600, 600);
    
    glutCreateWindow("Tutorial 01");

    return 0;
}