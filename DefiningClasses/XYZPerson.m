//
//  XYZPerson.m
//  DefiningClasses
//
//  Created by Lokesh Basu on 18/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "XYZPerson.h"

@implementation XYZPerson

- (void)sayHello
{
    [self saySomething:@"Hello, World!"];
}

- (void)saySomething:(NSString *)greeting
{
    NSLog(@"%@", greeting);
}

@end
