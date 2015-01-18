//
//  main.cpp
//  OpenGLProgramming
//
//  Created by Lokesh Basu on 09/12/14.
//  Copyright (c) 2014 InHouse. All rights reserved.
//

#include <SDL2/SDL.h>

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


void init()
{
    glClearColor(0, 1, 0, 1);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *screen = SDL_CreateWindow("Tutorial 1",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
    bool running = true;
    Uint32 start;
    SDL_Event event;
    while (running) {
        start = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        if (1000/3 > (SDL_GetTicks() - start)) {
            SDL_Delay(1000/3 - (SDL_GetTicks() - start));
        }
    }
    SDL_QUIT;
    return 0;
}