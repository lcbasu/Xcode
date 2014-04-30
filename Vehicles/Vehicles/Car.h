//
//  Car.h
//  Vehicles
//
//  Created by Lokesh Basu on 30/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Vehicle.h"

@interface Car : Vehicle

@property (nonatomic, assign) BOOL isConvertible;
@property (nonatomic, assign) BOOL isHatchback;
@property (nonatomic, assign) BOOL hasSunroof;
@property (nonatomic, assign) NSInteger numberOfDoors;

@end
