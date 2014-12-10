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

GLint attributeCoord2d;

int initResources()
{
    GLint compileStatus = GL_FALSE;
    GLint linkStatus = GL_FALSE;
    
    GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
    
    const char *vertexShaderSource =
#ifdef GL_ES_VERSION_2_0
    "#version 100\n"  // OpenGL ES 2.0
#else
    "#version 120\n"  // OpenGL 2.1
#endif
    "attribute vec2 coord2d;                  "
    "void main(void)"
    "{"
    "  gl_Position = vec4(coord2d, 0.0, 1.0); "
    "}";
    
    glShaderSource(vertexShaderHandle, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderHandle);
    glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &compileStatus);
    
    if (!compileStatus)
    {
        cout << "Error in vertex shader\n";
        return 0;
    }
    
    
    GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentShaderSource =
    "#version 120           \n"
    "void main(void)"
    "{"
    "  gl_FragColor = vec3(0.0, 1.0, 0.0); "
    "}";
    
    glShaderSource(fragmentShaderHandle, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderHandle);
    glGetShaderiv(fragmentShaderHandle, GL_COMPILE_STATUS, &compileStatus);
    
    if (!compileStatus)
    {
        cout << "Error in fragment shader\n";
        return 0;
    }
    
    GLuint program;
    
    program = glCreateProgram();
    
    glAttachShader(program, vertexShaderHandle);
    glAttachShader(program, fragmentShaderHandle);
    
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    
    if (!linkStatus) {
        cout << "Error in glLinkProgram:";
        return 0;
    }
    
    const char* attributeName = "coord2d";
    
    attributeCoord2d = glGetAttribLocation(program, attributeName);
    
    if (attributeCoord2d == -1)
    {
        cout << "Could not bind attribute: " << attributeName << endl;
        return 0;
    }
    
    return 1;
}

void onDisplay()
{
}

void freeResources()
{
    
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_3_2_CORE_PROFILE);
    
    glutInitWindowSize(600, 600);
    
    glutCreateWindow("Tutorial 01");
    
    if (initResources()) {
        glutDisplayFunc(onDisplay);
        glutMainLoop();
    }
    
    
    return 0;
}