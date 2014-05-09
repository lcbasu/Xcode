//
//  ViewController.m
//  QuoteGen
//
//  Created by Lokesh Basu on 07/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSString *plistCatPath = [[NSBundle mainBundle] pathForResource:@"quotes" ofType:@"plist"];
    self.movieQuotes= [NSMutableArray arrayWithContentsOfFile:plistCatPath];
    
    self.myQuotes = @[
                      @"Live and let live",
                      @"Don't cry over spilt milk",
                      @"Always look on the bright side of life",
                      @"Nobody's perfect",
                      @"Can't see the woods for the trees",
                      @"Better to have loved and lost then not loved at all",
                      @"The early bird catches the worm",
                      @"As slow as a wet week"
                      ];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)quoteButtonTapped:(id)sender
{
    int totalQuotes = [self.movieQuotes count];
    int index = (arc4random() % totalQuotes);
    //NSString *my_quote = [self.myQuotes objectAtIndex:index];
    NSString *my_quote = self.movieQuotes[index][@"quote"];
    self.quoteText.text = [NSString stringWithFormat:@"Quote:\n\n%@",  my_quote];
}

@end
