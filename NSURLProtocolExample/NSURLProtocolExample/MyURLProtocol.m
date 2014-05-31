//
//  MyURLProtocol.m
//  NSURLProtocolExample
//
//  Created by Lokesh Basu on 31/05/14.
//  Copyright (c) 2014 Rocir Santiago. All rights reserved.
//

#import "MyURLProtocol.h"

@implementation MyURLProtocol

+ (BOOL)canInitWithRequest:(NSURLRequest *)request
{
    static NSUInteger requestCount = 0;
    NSLog(@"Request #%u: URL = %@", requestCount++, request.URL.absoluteString);
    return NO;
}

@end
