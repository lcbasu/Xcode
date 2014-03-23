//
//  Card.m
//  LecRev1-3
//
//  Created by Lokesh Basu on 22/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Card.h"

@interface Card()

@end

@implementation Card



- (int)match:(NSArray *)otherCards
{
    int score = 0;
    
    for (Card *card in otherCards) {
        if ([card.contents isEqualToString:self.contents]) {
            score = 1;
        }
    }
    
    return score;
}

@end
