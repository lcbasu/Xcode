//
//  RWTScaryBugDoc.h
//  ScaryBugs
//
//  Created by Lokesh Basu on 12/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RWTScaryBugData.h"

@interface RWTScaryBugDoc : NSObject

@property (strong) RWTScaryBugData *data;
@property (strong) UIImage *thumbImage;
@property (strong) UIImage *fullImage;

- (id)initWithTitle:(NSString*)title rating:(float)rating thumbImage:(UIImage *)thumbImage fullImage:(UIImage *)fullImage;

@end
