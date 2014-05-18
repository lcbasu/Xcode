//
//  main.m
//  DefiningClasses
//
//  Created by Lokesh Basu on 18/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYZPerson.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool
    {
//        NSLog(@"Hello, World!");
        
        XYZPerson *personObj = [[XYZPerson alloc] init];
        
        [personObj sayHello];
        
    }
    return 0;
}

