//
//  PlayingCard.m
//  MatchismoV2
//
//  Created by Lokesh Basu on 23/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "PlayingCard.h"

@implementation PlayingCard

// overriding match method of Card class
- (int)match:(NSArray *)otherCards
{
    int score = 0;
    
    if ([otherCards count] == 1) {
        PlayingCard *firstCard = self;
        PlayingCard *secondCard = [otherCards firstObject];
        score = [self gameScoreWithFirstCards:firstCard secondCard:secondCard];
    } else if ([otherCards count] == 2) {
        // score for three card matching
        PlayingCard *firstCard = self;
        PlayingCard *secondCard = [otherCards firstObject];
        PlayingCard *thirdCard = [otherCards objectAtIndex:1];
        score = [self gameScoreWithFirstCards:firstCard secondCard:secondCard thirdCard:thirdCard];
    }
    return score;
}

- (int)gameScoreWithFirstCards:(PlayingCard *)firstCard secondCard:(PlayingCard *)secondCard
{
    return [self gameScoreWithFirstCards:firstCard secondCard:secondCard thirdCard:nil];
}

- (int)gameScoreWithFirstCards:(PlayingCard *)firstCard secondCard:(PlayingCard *)secondCard thirdCard:(PlayingCard *)thirdCard
{
    int score = 0;
    if (thirdCard == nil) {
        if ([firstCard.suit isEqualToString:secondCard.suit]) {
            score = 1;
        } else if (firstCard.rank == secondCard.rank) {
            score = 4;
        }
    } else {
        if ([firstCard.suit isEqualToString:secondCard.suit] || [secondCard.suit isEqualToString:thirdCard.suit] || [thirdCard.suit isEqualToString:firstCard.suit]) {
            score = 10;
        } else if (firstCard.rank == secondCard.rank || secondCard.rank == thirdCard.rank || thirdCard.rank == firstCard.rank) {
            score = 40;
        } else if ([firstCard.suit isEqualToString:secondCard.suit] && [secondCard.suit isEqualToString:thirdCard.suit]) {
            score = 50;
        } else if (firstCard.rank == secondCard.rank && secondCard.rank == thirdCard.rank) {
            score = 100;
        }
    }
    return score;
}

- (NSString *)contents
{
    NSArray *rankStrings = [PlayingCard rankStrings];
    return [rankStrings[self.rank] stringByAppendingString:self.suit];
}

@synthesize suit = _suit;

+ (NSArray *)validSuits
{
    return @[@"♥︎", @"♦︎", @"♠︎", @"♣︎"];
}

- (void)setSuit:(NSString *)suit
{
    if ([[PlayingCard validSuits] containsObject:suit]) {
        _suit = suit;
    }
}

- (NSString *)suit
{
    return  _suit ? _suit : @"?";
}

+ (NSArray *)rankStrings
{
    return @[@"?", @"A", @"2", @"3", @"4", @"5", @"6", @"7", @"8", @"9", @"10", @"J", @"Q", @"K"];
}

+ (NSUInteger)maxRank
{
    return [[self rankStrings] count]-1;
}

- (void)setRank:(NSUInteger)rank
{
    if (rank <= [PlayingCard maxRank]) {
        _rank = rank;
    }
}

@end
