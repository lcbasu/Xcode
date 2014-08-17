//
//  imageloader.h
//  OpenGL_T5
//
//  Created by Lokesh Basu on 17/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#ifndef OpenGL_T5_imageloader_h
#define OpenGL_T5_imageloader_h


class Image
{
public:
    Image(char *ps, int w, int h);
    ~Image();
    
    char *pixels;
    int width;
    int height;
};

Image *loadBMP(const char *filename);

#endif
