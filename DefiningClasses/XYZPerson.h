//
//  XYZPerson.h
//  DefiningClasses
//
//  Created by Lokesh Basu on 18/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XYZPerson : NSObject

@property NSString *firstName;
@property NSString *lastName;
@property NSDate *dob;

- (void)sayHello;
- (void)saySomething:(NSString *)greeting;

@end
