//
//  CardGameViewController.m
//  MatchismoV2
//
//  Created by Lokesh Basu on 23/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CardGameViewController.h"

@interface CardGameViewController ()

@end

@implementation CardGameViewController

- (IBAction)touchCardButton:(UIButton *)sender
{
    UIImage *cardImage = [UIImage imageNamed:@"cardback"];
    [sender setBackgroundImage:cardImage forState:UIControlStateNormal];
    [sender setTitle:@"" forState:UIControlStateNormal];
}


@end
