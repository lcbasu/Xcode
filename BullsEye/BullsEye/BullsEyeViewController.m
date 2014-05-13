//
//  BullsEyeViewController.m
//  BullsEye
//
//  Created by Lokesh Basu on 12/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "BullsEyeViewController.h"

@interface BullsEyeViewController ()

@end

@implementation BullsEyeViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)showAlert
{
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Hello, World!"
                                                        message:@"Bullys Eye test app"
                                                       delegate:nil
                                              cancelButtonTitle:@"Cancel"
                                              otherButtonTitles:nil];    
    [alertView show];
}

@end
