//
//  main.cpp
//  OpenGL_ES
//
//  Created by Lokesh Basu on 03/09/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// Handle to a program object
GLuint programObject;

GLuint LoadShader(GLenum type, string shaderSrc)
{
    GLuint shader;
    GLint compiled;
    
    shader = glCreateShader(type);
    
    glShaderSource(shader, 1, &shaderSrc, shaderSrc.size());
    
    //glShaderSource(shader, 1, &shaderSrc, NULL);
    
    glCompileShader(shader);
    
    return shader;
}

int Init()
{
    string vShaderStr = "";
    string fShaderStr = "";
    
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;
    
    vertexShader = LoadShader(GL_VERTEX_SHADER, vShaderStr);
    fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fShaderStr);
    
    // Create the program object
    programObject = glCreateProgram();
    
    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    return 1;
}

void draw(int width, int height)
{
    GLfloat vVertices[] = {
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
    
    glViewport(0, 0, width, height);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    
    glEnableVertexAttribArray(0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(int argc, char *argv[])
{
//    esCreateWindow(&esContext, "Hello Triangle", 320, 240, ES_WINDOW_RGB);
//    esRegisterDrawFunc(&esContext, Draw);
//    esMainLoop(&esContext);
    return 0;
}
