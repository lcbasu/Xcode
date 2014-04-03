//
//  Photographer+Create.h
//  Photomania
//
//  Created by Lokesh Basu on 03/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Photographer.h"

@interface Photographer (Create)

+ (Photographer *)photographerWithName:(NSString *)name
                inManagedObjectContext:(NSManagedObjectContext *)context;

@end
