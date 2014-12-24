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

GLuint program_;
GLint a_Position_;

char* fileRead(const char* fileName)
{
    FILE* in = fopen(fileName, "rb");
    if (in == NULL) return NULL;
    
    int resSize = BUFSIZ;
    char* res = (char*)malloc(resSize);
    int nbReadTotal = 0;
    
    while (!feof(in) && !ferror(in))
    {
        if (nbReadTotal + BUFSIZ > resSize)
        {
            if (resSize > 10*1024*1024)
                break;
            resSize = resSize * 2;
            res = (char*)realloc(res, resSize);
        }
        char* pRes = res + nbReadTotal;
        nbReadTotal += fread(pRes, 1, BUFSIZ, in);
    }
    
    fclose(in);
    res = (char*)realloc(res, nbReadTotal + 1);
    res[nbReadTotal] = '\0';
    return res;
}

/**
 * Display compilation errors from the OpenGL shader compiler
 */
void printLog(GLuint object)
{
    GLint logLength = 0;
    if (glIsShader(object))
        glGetShaderiv(object, GL_INFO_LOG_LENGTH, &logLength);
    else if (glIsProgram(object))
        glGetProgramiv(object, GL_INFO_LOG_LENGTH, &logLength);
    else {
        fprintf(stderr, "printlog: Not a shader or a program\n");
        return;
    }
    
    char* log = (char*)malloc(logLength);
    
    if (glIsShader(object))
        glGetShaderInfoLog(object, logLength, NULL, log);
    else if (glIsProgram(object))
        glGetProgramInfoLog(object, logLength, NULL, log);
    
    fprintf(stderr, "%s", log);
    free(log);
}

int initResources()
{
    GLint compileStatus = GL_FALSE, linkStatus = GL_FALSE;
    
    GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexShaderSource =
    "attribute vec2 coord2d;                  "
    "void main(void) {                        "
    "  gl_Position = vec4(coord2d, 0.0, 1.0); "
    "}";
    
    glShaderSource(vertexShaderHandle, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderHandle);
    glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &compileStatus);
    
    if (!compileStatus) {
        cout << "Error in vertex shader" << endl;
        return 0;
    }
    
    GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentShaderSource =
    "void main(void) {        "
    "  gl_FragColor[0] = 0.0; "
    "  gl_FragColor[1] = 0.0; "
    "  gl_FragColor[2] = 1.0; "
    "}";
    
    glShaderSource(fragmentShaderHandle, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderHandle);
    glGetShaderiv(fragmentShaderHandle, GL_COMPILE_STATUS, &compileStatus);
    
    if (!compileStatus) {
        cout << "Error in fragment shader" << endl;
        return 0;
    }
    
    program_ = glCreateProgram();
    glAttachShader(program_, vertexShaderHandle);
    glAttachShader(program_, fragmentShaderHandle);
    glLinkProgram(program_);
    glGetProgramiv(program_, GL_LINK_STATUS, &linkStatus);
    if (!linkStatus) {
        fprintf(stderr, "glLinkProgram:");
        return 0;
    }
    
    const char* a_Position = "coord2d";
    a_Position_ = glGetAttribLocation(program_, a_Position);
    if (a_Position_ == -1) {
        cout << "Could not bind attribute " << a_Position << endl;
        return 0;
    }
    
    return 1;
}

void onDisplay()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(program_);
    glEnableVertexAttribArray(a_Position_);
    GLfloat triangleVertices[] = {
        0.0,  0.8,
        -0.8, -0.8,
        0.8, -0.8,
    };
    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
                          a_Position_, // attribute
                          2,                 // number of elements per vertex, here (x,y)
                          GL_FLOAT,          // the type of each element
                          GL_FALSE,          // take our values as-is
                          0,                 // no extra data between each position
                          triangleVertices  // pointer to the C array
                          );
    
    /* Push each element in buffer_vertices to the vertex shader */
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableVertexAttribArray(a_Position_);
    glutSwapBuffers();
}

void freeResources()
{
    glDeleteProgram(program_);
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Tutorial 02");
    
    
    if (initResources()) {
        glutDisplayFunc(onDisplay);
        glutMainLoop();
    }
    
    freeResources();
    return 0;
}