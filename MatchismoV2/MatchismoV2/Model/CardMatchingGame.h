//
//  CardMatchingGame.h
//  MatchismoV2
//
//  Created by Lokesh Basu on 24/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Deck.h"

@interface CardMatchingGame : NSObject

// designated initializer
- (instancetype)initWithCardCount:(NSUInteger)count usingDeck:(Deck *)deck;

- (void)chooseCardAtIndex:(NSInteger)index;
- (Card *)cardAtIndex:(NSUInteger)index;

@property (nonatomic, readonly) NSInteger score;
@property (nonatomic) NSInteger gameMode;

@end
