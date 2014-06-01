//
//  Comms.h
//  FBParse
//
//  Created by Lokesh Basu on 01/06/14.
//  Copyright (c) 2014 Toby Stephens. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CommsDelegate <NSObject>

@optional
- (void) commsDidLogin:(BOOL)loggedIn;

@end

@interface Comms : NSObject

+ (void) login:(id<CommsDelegate>)delegate;

@end
