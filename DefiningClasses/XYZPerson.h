//
//  XYZPerson.h
//  DefiningClasses
//
//  Created by Lokesh Basu on 18/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XYZPerson : NSObject

// properties
@property NSString *firstName;
@property NSString *lastName;
@property NSDate *dob;
@property (readonly) NSString *fullName;

// methods
- (void)sayHello;
- (void)saySomething:(NSString *)greeting;

// custom initializers
- (id)initWithFirstName:(NSString *)aFirstName lastname:(NSString *)aLastname;

- (id)initWithFirstName:(NSString *)aFirstName lastname:(NSString *)aLastname dateOfBirth:(NSDate *)aDOB;

@end
