//
//  PlayingCard.m
//  Matchismo
//
//  Created by Lokesh Basu on 20/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "PlayingCard.h"

@implementation PlayingCard

- (int)match:(NSArray *)otherCards
{
    int score = 0;
    
    if ([otherCards count] == 1) {
        PlayingCard *firstCard = [otherCards firstObject];
        if ([self.suit isEqualToString:firstCard.suit]) {
            score = 1;
        } else if (self.rank == firstCard.rank) {
            score = 4;
        }
    } else if ([otherCards count] == 2) {
        PlayingCard *firstCard = [otherCards objectAtIndex:0];
        PlayingCard *secondCard = [otherCards objectAtIndex:1];
        if ([self.suit isEqualToString:firstCard.suit] || [self.suit isEqualToString:secondCard.suit]) {
            score = 1;
        } else if (self.rank == firstCard.rank || self.rank == secondCard.rank) {
            score = 2;
        } else if ([self.suit isEqualToString:firstCard.suit] && [self.suit isEqualToString:secondCard.suit]) {
            score = 4;
        } else if (self.rank == firstCard.rank && self.rank == secondCard.rank) {
            score = 8;
        }
    }
    
    return score;
}

- (NSString *)contents
{
    NSArray *rankStrings = [PlayingCard rankStrings];
    return [rankStrings[self.rank] stringByAppendingString:self.suit];
}

@synthesize suit = _suit;   //becuase we defined both setter and getter

+(NSArray *)validSuits
{
    return @[@"♥︎",@"♦︎",@"♠︎",@"♣︎"];
}

- (void)setSuit:(NSString *)suit
{
    if ([[PlayingCard validSuits] containsObject:suit])
    {
        _suit = suit;
    }
}

- (NSString *)suit
{
    return _suit ? _suit : @"?";
}

+ (NSArray *)rankStrings
{
    return @[@"?",@"A",@"2",@"3",@"4",@"5",@"6",
             @"7",@"8",@"9",@"10",@"J",@"Q",@"K"];
}

+ (NSUInteger)maxRank { return [[self rankStrings] count]-1; }

- (void)setRank:(NSUInteger)rank
{
    if(rank <= [PlayingCard maxRank]) {
        _rank = rank;
    }
}

@end
