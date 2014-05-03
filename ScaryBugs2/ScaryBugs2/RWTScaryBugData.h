//
//  RWTScaryBugData.h
//  ScaryBugs2
//
//  Created by Lokesh Basu on 03/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RWTScaryBugData : NSObject

@property (strong, nonatomic) NSString *title;
@property (assign, nonatomic) float rating;

- (id)initWithTitle:(NSString*)title rating:(float)rating;

@end
