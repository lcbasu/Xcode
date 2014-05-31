//
//  MyURLProtocol.m
//  NSURLProtocolExample
//
//  Created by Lokesh Basu on 31/05/14.
//  Copyright (c) 2014 Rocir Santiago. All rights reserved.
//

#import "MyURLProtocol.h"

@interface MyURLProtocol () <NSURLConnectionDelegate>
@property (nonatomic, strong) NSURLConnection *connection;
@end

@implementation MyURLProtocol

+ (BOOL)canInitWithRequest:(NSURLRequest *)request
{
    static NSUInteger requestCount = 0;
    NSLog(@"Request #%u: URL = %@", requestCount++, request.URL.absoluteString);
    return YES;
}

#pragma mark - connection delegate methods

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
    [self.client URLProtocol:self didReceiveResponse:response cacheStoragePolicy:NSURLCacheStorageNotAllowed];
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    [self.client URLProtocol:self didLoadData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    [self.client URLProtocolDidFinishLoading:self];
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    [self.client URLProtocol:self didFailWithError:error];
}

#pragma mark - request methods

+ (NSURLRequest *)canonicalRequestForRequest:(NSURLRequest *)request {
    return request;
}

+ (BOOL)requestIsCacheEquivalent:(NSURLRequest *)a toRequest:(NSURLRequest *)b {
    return [super requestIsCacheEquivalent:a toRequest:b];
}

- (void)startLoading {
    self.connection = [NSURLConnection connectionWithRequest:self.request delegate:self];
}

- (void)stopLoading {
    [self.connection cancel];
    self.connection = nil;
}

@end
