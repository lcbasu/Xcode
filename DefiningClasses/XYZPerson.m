//
//  XYZPerson.m
//  DefiningClasses
//
//  Created by Lokesh Basu on 18/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "XYZPerson.h"

@implementation XYZPerson

// custom initializer implementations
- (id)initWithFirstName:(NSString *)aFirstName lastname:(NSString *)aLastname dateOfBirth:(NSDate *)aDOB
{
    self = [super init];
    
    if (self) {
        _firstName = aFirstName;
        _lastName = aLastname;
        _dob = aDOB;
    }
    return self;
}

- (id)initWithFirstName:(NSString *)aFirstName lastname:(NSString *)aLastname
{
    return [self initWithFirstName:aFirstName lastname:aLastname dateOfBirth:nil];
}

- (id)init
{
    return [self initWithFirstName:@"Lokesh" lastname:@"Basu" dateOfBirth:8/10/1992];
}

// method implementation
- (void)sayHello
{
    [self saySomething:@"Hello, World!"];
}

- (void)saySomething:(NSString *)greeting
{
    NSLog(@"%@", greeting);
}

// custom getter method
- (NSString *)fullName
{
    return [NSString stringWithFormat:@"%@ %@", self.firstName, self.lastName];
}

@end
