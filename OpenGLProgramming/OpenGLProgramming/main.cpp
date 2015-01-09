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
#include <math.h>

#include "glm.hpp"
#include "matrix_transform.hpp"
#include "quaternion.hpp"
#include "type_ptr.hpp"

using namespace std;

int screenWidth=1100, screenHeight=600;

GLuint program_;
GLint a_Position_, a_Color_;
GLuint vboTriangle, vboTriangleColors;
GLuint vboCubeVertices, vboCubeColors;
GLuint iboCubeElements;
GLint uniformFade;
GLint uniformMVP;

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
    GLint compileStatus = GL_FALSE;
    glGetShaderiv(res, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE) {
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
    GLint linkStatus = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if (!linkStatus) {
        fprintf(stderr, "glLinkProgram:");
        printLog(program);
        glDeleteProgram(program);
        return 0;
    }
    
    return program;
}

GLuint createGsProgram(const char *vertexfile, const char *geometryfile, const char *fragmentfile, GLint input, GLint output, GLint vertices)
{
    fprintf(stderr, "Missing support for geometry shaders.\n");
    return 0;
}

GLint getAttrib(GLuint program, const char *name)
{
    GLint attribute = glGetAttribLocation(program, name);
    if(attribute == -1)
        fprintf(stderr, "Could not bind attribute %s\n", name);
    return attribute;
}

GLint getUniform(GLuint program, const char *name)
{
    GLint uniform = glGetUniformLocation(program, name);
    if(uniform == -1)
        fprintf(stderr, "Could not bind uniform %s\n", name);
    return uniform;
}

int initResources()
{
    GLfloat cubeVertices[] = {
        // front
        -1.0, -1.0,  1.0,
        1.0, -1.0,  1.0,
        1.0,  1.0,  1.0,
        -1.0,  1.0,  1.0,
        // back
        -1.0, -1.0, -1.0,
        1.0, -1.0, -1.0,
        1.0,  1.0, -1.0,
        -1.0,  1.0, -1.0,
    };
    glGenBuffers(1, &vboCubeVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboCubeVertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    
    GLfloat cubeColors[] = {
        // front colors
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
        // back colors
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
    };
    glGenBuffers(1, &vboCubeColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboCubeColors);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeColors), cubeColors, GL_STATIC_DRAW);
    
    GLushort cubeElements[] = {
        // front
        0, 1, 2,
        2, 3, 0,
        // top
        1, 5, 6,
        6, 2, 1,
        // back
        7, 6, 5,
        5, 4, 7,
        // bottom
        4, 0, 3,
        3, 7, 4,
        // left
        4, 5, 1,
        1, 0, 4,
        // right
        3, 2, 6,
        6, 7, 3,
    };
    glGenBuffers(1, &iboCubeElements);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboCubeElements);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeElements), cubeElements, GL_STATIC_DRAW);
    
    GLint linkStatus = GL_FALSE;
    
    GLuint vertexShader, fragmentShader;
    if ((vertexShader = createShader("/Users/LokeshBasu/Documents/Xcode/OpenGLProgramming/OpenGLProgramming/cube.v.glsl", GL_VERTEX_SHADER))   == 0) return 0;
    if ((fragmentShader = createShader("/Users/LokeshBasu/Documents/Xcode/OpenGLProgramming/OpenGLProgramming/cube.f.glsl", GL_FRAGMENT_SHADER)) == 0) return 0;
    
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
    
    const char* attributeName = "coord3d";
    a_Position_ = glGetAttribLocation(program_, attributeName);
    if (a_Position_ == -1) {
        fprintf(stderr, "Could not bind attribute %s\n", attributeName);
        return 0;
    }
    
    attributeName = "v_color";
    a_Color_ = glGetAttribLocation(program_, attributeName);
    if (a_Color_ == -1) {
        fprintf(stderr, "Could not bind attribute %s\n", attributeName);
        return 0;
    }
    
    const char* uniformName;
    uniformName = "mvp";
    uniformMVP = glGetUniformLocation(program_, uniformName);
    if (uniformMVP == -1) {
        fprintf(stderr, "Could not bind uniform_fade %s\n", uniformName);
        return 0;
    }
    
    
    return 1;
}

void onDisplay()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(program_);
    glEnableVertexAttribArray(a_Position_);
    // Describe our vertices array to OpenGL (it can't guess its format automatically)
    glBindBuffer(GL_ARRAY_BUFFER, vboCubeVertices);
    glVertexAttribPointer(
                          a_Position_, // attribute
                          3,                 // number of elements per vertex, here (x,y,z)
                          GL_FLOAT,          // the type of each element
                          GL_FALSE,          // take our values as-is
                          0,                 // no extra data between each position
                          0                  // offset of first element
                          );
    
    glEnableVertexAttribArray(a_Color_);
    glBindBuffer(GL_ARRAY_BUFFER, vboCubeColors);
    glVertexAttribPointer(
                          a_Color_, // attribute
                          3,                 // number of elements per vertex, here (R,G,B)
                          GL_FLOAT,          // the type of each element
                          GL_FALSE,          // take our values as-is
                          0,                 // no extra data between each position
                          0                  // offset of first element
                          );
    
    /* Push each element in buffer_vertices to the vertex shader */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboCubeElements);
    int size;  glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    glDrawElements(GL_TRIANGLES, size/sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
    
    glDisableVertexAttribArray(a_Position_);
    glDisableVertexAttribArray(a_Color_);
    glutSwapBuffers();
}

void onIdle()
{
    float angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0 * 20;  // 45° per second
    glm::vec3 axisY(0, 1, 0);
    glm::mat4 anim = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axisY);
    
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
    glm::mat4 view = glm::lookAt(glm::vec3(0.0, 2.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 projection = glm::perspective(45.0f, 1.0f*screenWidth/screenHeight, 0.3f, 15.0f);
    
    glm::mat4 mvp = projection * view * model * anim;
    
    glUseProgram(program_);
    glUniformMatrix4fv(uniformMVP, 1, GL_FALSE, glm::value_ptr(mvp));
    glutPostRedisplay();
}

void freeResources()
{
    glDeleteProgram(program_);
    glDeleteBuffers(1, &vboCubeVertices);
    glDeleteBuffers(1, &vboCubeColors);
    glDeleteBuffers(1, &iboCubeElements);
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Tutorial 02");
    
    
    if (initResources()) {
        glutDisplayFunc(onDisplay);
        glutIdleFunc(onIdle);
        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glutMainLoop();
    }
    freeResources();
    return 0;
}