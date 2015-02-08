//
//  main.cpp
//  OpenGLProgramming
//
//  Created by Lokesh Basu on 09/12/14.
//  Copyright (c) 2014 InHouse. All rights reserved.
//

#include <iostream>
#include <SDL/SDL.h>
#include "GLee.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "camera.h"
#include <vector>
#include <string>
#include <fstream>

camera cam;
//data->vertex->fragment

void loadFile(const char* fn,std::string& str)
{
    std::ifstream in(fn);
    if(!in.is_open())
    {
        std::cout << "The file " << fn << " cannot be opened\n";
        return;
    }
    char tmp[300];
    while(!in.eof())
    {
        in.getline(tmp,300);
        str+=tmp;
        str+='\n';
    }
}

unsigned int loadShader(std::string& source,unsigned int mode)
{
    unsigned int id;
    id=glCreateShader(mode);
    
    const char* csource=source.c_str();
    
    glShaderSource(id,1,&csource,NULL);
    glCompileShader(id);
    char error[1000];
    glGetShaderInfoLog(id,1000,NULL,error);
    std::cout << "Compile status: \n" << error << std::endl;
    return id;
}

unsigned int vs,fs,program;

void initShader(const char* vname,const char* fname)
{
    std::string source;
    loadFile(vname,source);
    vs=loadShader(source,GL_VERTEX_SHADER);
    source="";
    loadFile(fname,source);
    fs=loadShader(source,GL_FRAGMENT_SHADER);
    
    program=glCreateProgram();
    glAttachShader(program,vs);
    glAttachShader(program,fs);
    
    glLinkProgram(program);
    glUseProgram(program);
}

void clean()
{
    glDetachShader(program,vs);
    glDetachShader(program,fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
    glDeleteProgram(program);
}

void init()
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50,640.0/480.0,1,1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    initShader("vertex.vs","fragment.frag");
}

void display()
{
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    cam.Control();
    cam.UpdateCamera();
    
    glBegin(GL_TRIANGLES);
    glVertex3f(0,1,-4);
    glVertex3f(-1,-1,-4);
    glVertex3f(1,-1,-4);
    glEnd();
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetVideoMode(640,480,32,SDL_OPENGL);
    Uint32 start;
    SDL_Event event;
    bool running=true;
    init();
    bool b=false;
    while(running)
    {
        start=SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running=false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        running=false;
                        break;
                }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    cam.mouseIn(true);
                    break;
                    
            }
        }
        display();
        SDL_GL_SwapBuffers();
        if(1000.0/30>SDL_GetTicks()-start)
            SDL_Delay(1000.0/30-(SDL_GetTicks()-start));
    }
    clean();
    SDL_Quit();
}