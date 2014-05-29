//
//  BeerDetails.h
//  BeerTracker
//
//  Created by Lokesh Basu on 29/05/14.
//  Copyright (c) 2014 Andy Pereira. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Beer;

@interface BeerDetails : NSManagedObject

@property (nonatomic, retain) NSString * image;
@property (nonatomic, retain) NSString * note;
@property (nonatomic, retain) NSNumber * rating;
@property (nonatomic, retain) Beer *beer;

@end
