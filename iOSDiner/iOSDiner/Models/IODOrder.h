//
//  IODOrder.h
//  iOSDiner
//
//  Created by Lokesh Basu on 31/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IODItem;
@interface IODOrder : NSObject

@property (nonatomic,strong) NSMutableDictionary* orderItems;

@end
