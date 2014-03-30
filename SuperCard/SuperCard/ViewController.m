//
//  ViewController.m
//  SuperCard
//
//  Created by Lokesh Basu on 30/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"
#import "PlayingCardView.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet PlayingCardView *playingCardView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.playingCardView.suit = @"♥︎";
    self.playingCardView.rank = 13;
}


@end
