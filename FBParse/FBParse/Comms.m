//
//  Comms.m
//  FBParse
//
//  Created by Lokesh Basu on 01/06/14.
//  Copyright (c) 2014 Toby Stephens. All rights reserved.
//

#import "Comms.h"

@implementation Comms

+ (void) login:(id<CommsDelegate>)delegate
{
	// basic user information
	[PFFacebookUtils logInWithPermissions:nil block:^(PFUser *user, NSError *error) {
        
		// Was login successful ?
		if (!user) {
			if (!error) {
                NSLog(@"The user cancelled the Facebook login.");
            } else {
                NSLog(@"An error occurred: %@", error.localizedDescription);
            }
            
			// Callback - login failed
			if ([delegate respondsToSelector:@selector(commsDidLogin:)]) {
				[delegate commsDidLogin:NO];
			}
		} else {
			if (user.isNew) {
				NSLog(@"User signed up and logged in through Facebook!");
			} else {
				NSLog(@"User logged in through Facebook!");
			}
            
			// Callback - login successful
			if ([delegate respondsToSelector:@selector(commsDidLogin:)]) {
				[delegate commsDidLogin:YES];
			}
		}
	}];
}

@end
