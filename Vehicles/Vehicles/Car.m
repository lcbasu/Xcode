//
//  Car.m
//  Vehicles
//
//  Created by Lokesh Basu on 30/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Car.h"

@implementation Car

- (id)init
{
    if (self = [super init]) {
        // Since all cars have four wheels, we can safely set this for every initialized instance
        // of a car.
        self.numberOfWheels = 4;
    }
    return self;
}

@end
