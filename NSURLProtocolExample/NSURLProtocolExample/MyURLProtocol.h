//
//  MyURLProtocol.h
//  NSURLProtocolExample
//
//  Created by Lokesh Basu on 31/05/14.
//  Copyright (c) 2014 Rocir Santiago. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MyURLProtocol : NSURLProtocol

@property (nonatomic, strong) NSMutableData *mutableData;
@property (nonatomic, strong) NSURLResponse *response;

@end
