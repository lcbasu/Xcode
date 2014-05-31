//
//  CachedURLResponse.h
//  NSURLProtocolExample
//
//  Created by Lokesh Basu on 31/05/14.
//  Copyright (c) 2014 Rocir Santiago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface CachedURLResponse : NSManagedObject

@property (nonatomic, retain) NSDate * timeStamp;
@property (nonatomic, retain) NSData * data;
@property (nonatomic, retain) NSString * encoding;
@property (nonatomic, retain) NSString * mimeType;
@property (nonatomic, retain) NSString * url;

@end
