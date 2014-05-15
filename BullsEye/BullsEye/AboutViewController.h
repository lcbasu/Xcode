//
//  AboutViewController.h
//  BullsEye
//
//  Created by Lokesh Basu on 15/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AboutViewController : UIViewController

@property (strong, nonatomic) IBOutlet UIWebView *webView;

- (IBAction)close;

@end
