//
//  PlayingCard.h
//  MatchismoV2
//
//  Created by Lokesh Basu on 23/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Card.h"

@interface PlayingCard : Card

@property (strong, nonatomic) NSString *suit;
@property (nonatomic) NSUInteger rank;

+ (NSArray *)validSuits;
+ (NSUInteger)maxRank;

@end
