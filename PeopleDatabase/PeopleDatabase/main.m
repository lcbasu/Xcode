//
//  main.m
//  PeopleDatabase
//
//  Created by Lokesh Basu on 14/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        //  using NSString
        
        
        NSString *name = [NSString stringWithFormat:@"\nLokesh Chandra Basu, DOB : %i.", 8];
        
        
        NSLog(@"%@", name);
        
    }
    return 0;
}

