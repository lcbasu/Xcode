//
//  PhotomaniaAppDelegate+MOC.h
//  Photomania
//
//  Created by Lokesh Basu on 03/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "PhotomaniaAppDelegate.h"

@interface PhotomaniaAppDelegate (MOC)

- (void)saveContext:(NSManagedObjectContext *)managedObjectContext;

- (NSManagedObjectContext *)createMainQueueManagedObjectContext;

@end