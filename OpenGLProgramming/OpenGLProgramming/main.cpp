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
GLuint vboTriangle;

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

/**
 * Compile the shader from file 'fileName', with error handling
 */
GLuint createShader(const char* fileName, GLenum type)
{
    const GLchar* source = fileRead(fileName);
    if (source == NULL) {
        fprintf(stderr, "Error opening %s: ", fileName); perror("");
        return 0;
    }
    GLuint res = glCreateShader(type);
    const GLchar* sources[] = {
        // Define GLSL version
#ifdef GL_ES_VERSION_2_0
        "#version 100\n"
#else
        "#version 120\n"
#endif
        ,
        // GLES2 precision specifiers
#ifdef GL_ES_VERSION_2_0
        // Define default float precision for fragment shaders:
        (type == GL_FRAGMENT_SHADER) ?
        "#ifdef GL_FRAGMENT_PRECISION_HIGH\n"
        "precision highp float;           \n"
        "#else                            \n"
        "precision mediump float;         \n"
        "#endif                           \n"
        : ""
        // Note: OpenGL ES automatically defines this:
        // #define GL_ES
#else
        // Ignore GLES 2 precision specifiers:
        "#define lowp   \n"
        "#define mediump\n"
        "#define highp  \n"
#endif
        ,
        source };
    glShaderSource(res, 3, sources, NULL);
    free((void*)source);
    
    glCompileShader(res);
    GLint compile_ok = GL_FALSE;
    glGetShaderiv(res, GL_COMPILE_STATUS, &compile_ok);
    if (compile_ok == GL_FALSE) {
        fprintf(stderr, "%s:", fileName);
        printLog(res);
        glDeleteShader(res);
        return 0;
    }
    
    return res;
}

GLuint createProgram(const char *vertexfile, const char *fragmentfile) {
    GLuint program = glCreateProgram();
    GLuint shader;
    
    if(vertexfile) {
        shader = createShader(vertexfile, GL_VERTEX_SHADER);
        if(!shader)
            return 0;
        glAttachShader(program, shader);
    }
    
    if(fragmentfile) {
        shader = createShader(fragmentfile, GL_FRAGMENT_SHADER);
        if(!shader)
            return 0;
        glAttachShader(program, shader);
    }
    
    glLinkProgram(program);
    GLint link_ok = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
    if (!link_ok) {
        fprintf(stderr, "glLinkProgram:");
        printLog(program);
        glDeleteProgram(program);
        return 0;
    }
    
    return program;
}


int initResources()
{
    GLfloat triangleVertices[] = {
        0.0,  0.8,
        -0.8, -0.8,
        0.8, -0.8,
    };
    
    glGenBuffers(1, &vboTriangle);
    glBindBuffer(GL_ARRAY_BUFFER, vboTriangle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
    
    GLint linkStatus = GL_FALSE;
    
    GLuint vertexShader, fragmentShader;
    if ((vertexShader = createShader("/Users/LokeshBasu/Documents/Xcode/OpenGLProgramming/OpenGLProgramming/triangle.v.glsl", GL_VERTEX_SHADER))   == 0) return 0;
    if ((fragmentShader = createShader("/Users/LokeshBasu/Documents/Xcode/OpenGLProgramming/OpenGLProgramming/triangle.f.glsl", GL_FRAGMENT_SHADER)) == 0) return 0;
    
    program_ = glCreateProgram();
    glAttachShader(program_, vertexShader);
    glAttachShader(program_, fragmentShader);
    glLinkProgram(program_);
    glGetProgramiv(program_, GL_LINK_STATUS, &linkStatus);
    if (!linkStatus) {
        fprintf(stderr, "glLinkProgram:");
        printLog(program_);
        return 0;
    }
    
    const char* attributeName = "coord2d";
    a_Position_ = glGetAttribLocation(program_, attributeName);
    if (a_Position_ == -1) {
        fprintf(stderr, "Could not bind attribute %s\n", attributeName);
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
    
    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
                          a_Position_, // attribute
                          2,                 // number of elements per vertex, here (x,y)
                          GL_FLOAT,          // the type of each element
                          GL_FALSE,          // take our values as-is
                          0,                 // no extra data between each position
                          0                  // offset of first element
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