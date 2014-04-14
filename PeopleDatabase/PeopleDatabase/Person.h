//
//  Person.h
//  PeopleDatabase
//
//  Created by Lokesh Basu on 14/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Person : NSObject {
    NSString *firstName;
    NSString *lastName;
    int age;
}

- (void)enterInfo;
- (void)printInfo;

@end
