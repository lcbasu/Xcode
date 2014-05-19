//
//  XYZShoutingPerson.m
//  DefiningClasses
//
//  Created by Lokesh Basu on 19/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "XYZShoutingPerson.h"

@implementation XYZShoutingPerson

- (void)saySomething:(NSString *)greeting
{
    NSString *upperCaseString = [greeting uppercaseString];
    [super saySomething:upperCaseString];
}

@end
