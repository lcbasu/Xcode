//
//  Beer.h
//  BeerTracker
//
//  Created by Lokesh Basu on 29/05/14.
//  Copyright (c) 2014 Andy Pereira. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Beer : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSManagedObject *beerDetails;

@end
