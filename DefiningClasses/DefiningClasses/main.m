//
//  main.m
//  DefiningClasses
//
//  Created by Lokesh Basu on 18/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYZPerson.h"
#import "XYZShoutingPerson.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool
    {
//        NSLog(@"Hello, World!");
        
        XYZPerson *normalPerson = [[XYZPerson alloc] init];
        
        [normalPerson sayHello];
        
        // super demo
        XYZShoutingPerson *shoutingperson = [[XYZShoutingPerson alloc] init];
        [shoutingperson sayHello];
        
    }
    return 0;
}

