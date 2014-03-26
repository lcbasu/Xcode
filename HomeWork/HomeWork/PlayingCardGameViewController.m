//
//  PlayingCardGameViewController.m
//  HomeWork
//
//  Created by Lokesh Basu on 26/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "PlayingCardGameViewController.h"
#import "PlayingCardDeck.h"

@interface PlayingCardGameViewController ()

@end

@implementation PlayingCardGameViewController


- (Deck *)createDeck
{
    return [[PlayingCardDeck alloc] init];
}

@end
