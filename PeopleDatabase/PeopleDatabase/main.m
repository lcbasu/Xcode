//
//  main.m
//  PeopleDatabase
//
//  Created by Lokesh Basu on 14/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        Person *newPerson = [[Person alloc] init];
        
        [newPerson enterInfo];
        [newPerson printInfo];
    }
    return 0;
}

