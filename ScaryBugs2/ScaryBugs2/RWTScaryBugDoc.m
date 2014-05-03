//
//  RWTScaryBugDoc.m
//  ScaryBugs2
//
//  Created by Lokesh Basu on 03/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "RWTScaryBugDoc.h"
#import "RWTScaryBugData.h"

@implementation RWTScaryBugDoc

@synthesize data = _data;
@synthesize thumbImage = _thumbImage;
@synthesize fullImage = _fullImage;

- (id)initWithTitle:(NSString*)title rating:(float)rating thumbImage:(UIImage *)thumbImage fullImage:(UIImage *)fullImage {
    if ((self = [super init])) {
        self.data = [[RWTScaryBugData alloc] initWithTitle:title rating:rating];
        self.thumbImage = thumbImage;
        self.fullImage = fullImage;
    }
    return self;
}

@end
