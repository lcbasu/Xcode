//
//  IODViewController.m
//  iOSDiner
//
//  Created by Adam Burkepile on 1/29/12.
//  Copyright (c) 2012 Adam Burkepile. All rights reserved.
//

#import "IODViewController.h"
#import "IODItem.h"
#import "IODOrder.h"

@implementation IODViewController

@synthesize order;
@synthesize inventory;

@synthesize ibRemoveItemButton;
@synthesize ibAddItemButton;
@synthesize ibPreviousItemButton;
@synthesize ibNextItemButton;
@synthesize ibTotalOrderButton;
@synthesize ibChalkboardLabel;
@synthesize ibCurrentItemImageView;
@synthesize ibCurrentItemLabel;

dispatch_queue_t queue;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    queue = dispatch_queue_create("com.basu.queue",nil);
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    currentItemIndex = 0;
    self.order = [IODOrder new];
}

- (void)viewDidUnload
{
    [self setIbRemoveItemButton:nil];
    [self setIbAddItemButton:nil];
    [self setIbPreviousItemButton:nil];
    [self setIbNextItemButton:nil];
    [self setIbTotalOrderButton:nil];
    [self setIbChalkboardLabel:nil];
    [self setIbCurrentItemImageView:nil];
    [self setIbCurrentItemLabel:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    // set initial label text
	ibChalkboardLabel.text = @"Loading Inventory...";
	// 2 - Use queue to fetch inventory and then set label text
    dispatch_async(queue, ^{
		self.inventory = [[IODItem retrieveInventoryItems] mutableCopy];
		dispatch_async(dispatch_get_main_queue(), ^{
			ibChalkboardLabel.text = @"Inventory Loaded\n\nHow can I help you?";
		});
	});
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

- (IBAction)ibaRemoveItem:(id)sender {
}

- (IBAction)ibaAddItem:(id)sender {
}

- (IBAction)ibaLoadPreviousItem:(id)sender {
}

- (IBAction)ibaLoadNextItem:(id)sender {
}

- (IBAction)ibaCalculateTotal:(id)sender {
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (void)dealloc
{
    dispatch_release(queue);
}

@end
