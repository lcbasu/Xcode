//
//  Card.m
//  HomeWork
//
//  Created by Lokesh Basu on 23/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Card.h"

@implementation Card

-(int)match:(NSArray *)otherCards
{
    int score = 0;
    
    return score;
    for(Card *card in otherCards)
    {
        if([card.contents isEqualToString:self.contents])
        {
            score = 1;
        }
    }
}

@end