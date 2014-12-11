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
GLuint program;

int initResources()
{
    GLint compileStatus = GL_FALSE;
    GLint linkStatus = GL_FALSE;
    
    GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
    
    const char *vertexShaderSource =
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
    /* Clear the background as white */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(program);
    glEnableVertexAttribArray(attributeCoord2d);
    
    GLfloat triangleVertices[] = {
        0.0,  0.8,
        -0.8, -0.8,
        0.8, -0.8,
    };
    
    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
                          attributeCoord2d,     // attribute
                          2,                    // number of elements per vertex, here (x,y)
                          GL_FLOAT,             // the type of each element
                          GL_FALSE,             // take our values as-is
                          0,                    // no extra data between each position
                          triangleVertices      // pointer to the C array
                          );
    /* Push each element in buffer_vertices to the vertex shader */
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(attributeCoord2d);
    
    /* Display the result */
    glutSwapBuffers();
}

void freeResources()
{
    glDeleteProgram(program);
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
    
    freeResources();
    
    return 0;
}