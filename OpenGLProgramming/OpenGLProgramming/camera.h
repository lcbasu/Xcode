//
//  camera.h
//  OpenGLProgramming
//
//  Created by Lokesh Basu on 08/02/15.
//  Copyright (c) 2015 InHouse. All rights reserved.
//

#ifndef OpenGLProgramming_camera_h
#define OpenGLProgramming_camera_h

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <math.h>
#include "vector3d.h"

class camera{
    vector3d loc;
    float camPitch,camYaw;
    float movevel;
    float mousevel;
    bool mi,ismoved;
    void lockCamera();
    void moveCamera(float dir);
    void moveCameraUp(float dir);
public:
    camera();
    camera(vector3d loc);
    camera(vector3d loc,float yaw,float pitch);
    camera(vector3d loc,float yaw,float pitch,float mv,float mov);
    void Control();
    void UpdateCamera();
    vector3d getVector();
    vector3d getLocation();
    float getPitch();
    float getYaw();
    float getMovevel();
    float getMousevel();
    bool isMouseIn();
    
    void setLocation(vector3d vec);
    void lookAt(float pitch,float yaw);
    void mouseIn(bool b);
    void setSpeed(float mv,float mov);
    
    bool isMoved();
};

#endif
