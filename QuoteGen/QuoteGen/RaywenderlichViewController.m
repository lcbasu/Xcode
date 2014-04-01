//
//  RaywenderlichViewController.m
//  QuoteGen
//
//  Created by Lokesh Basu on 01/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "RaywenderlichViewController.h"

@interface RaywenderlichViewController ()

@end

@implementation RaywenderlichViewController


@synthesize myQuotes;
@synthesize movieQuotes;


- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.myQuotes = [NSArray arrayWithObjects:
                     @"Live and let live",
                     @"Don't cry over spilt milk",
                     @"Always look on the bright side of life",
                     @"Nobody's perfect",
                     @"Can't see the woods for the trees",
                     @"Better to have loved and lost than not loved at all",
                     @"The early bird catches the worm",
                     @"As slow as a wet week",
                     nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
