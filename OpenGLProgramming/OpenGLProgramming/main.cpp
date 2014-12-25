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

/**
 * Compile the shader from file 'fileName', with error handling
 */
GLuint create_shader(const char* fileName, GLenum type)
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