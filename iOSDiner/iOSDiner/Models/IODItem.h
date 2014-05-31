//
//  IODItem.h
//  iOSDiner
//
//  Created by Lokesh Basu on 31/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IODItem : NSObject <NSCopying>

@property (nonatomic,strong) NSString* name;
@property (nonatomic,assign) float price;
@property (nonatomic,strong) NSString* pictureFile;

- (id)initWithName:(NSString*)inName andPrice:(float)inPrice andPictureFile:(NSString*)inPictureFile;
+ (NSArray*)retrieveInventoryItems;

@end
