//
//  PlayingCard.h
//  Matchismo
//
//  Created by Lokesh Basu on 21/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Card.h"

@interface PlayingCard : Card

@property (Strong, nonatomic) NSString *suit;
@property (nonatomic) NSUInteger rank;

+ (NSArray *)validSuits;

@end;