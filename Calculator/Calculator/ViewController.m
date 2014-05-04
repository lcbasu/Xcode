//
//  ViewController.m
//  Calculator
//
//  Created by Lokesh Basu on 04/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize display = _display;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    _display.text = @"0";
}
- (IBAction)digitPressed:(id)sender
{
    NSString *digit = [sender currentTitle];
    _display.text = [_display.text stringByAppendingString:digit];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
