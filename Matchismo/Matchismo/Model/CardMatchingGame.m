//
//  CardMatchingGame.m
//  Matchismo
//
//  Created by Lokesh Basu on 21/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CardMatchingGame.h"

@interface CardMatchingGame()

@property (nonatomic, readwrite) NSInteger score;
@property (nonatomic, strong) NSMutableArray *cards;    //array of Card
@property (nonatomic, strong) NSMutableArray *currentCards; //cards to match when playing for three matching card
@end

@implementation CardMatchingGame


- (NSMutableArray *)currentCards
{
    if (!_currentCards) _currentCards = [[NSMutableArray alloc] init];
    return _currentCards;
}

- (NSMutableArray *)cards
{
    if(!_cards) _cards = [[NSMutableArray alloc] init];
    return _cards;
}

- (instancetype)initWithCardCount:(NSUInteger)count usingDeck:(Deck *)deck
{
    self = [super init];
    
    if (self) {
        for (int i = 0; i < count; i++) {
            Card *card = [deck drawRandomCard];
            if (card) {
                [self.cards addObject:card];
            } else {
                self = nil;
                break;
            }
        }
    }
    
    return self;
}

static const int MATCH_BONUS = 4;
static const int MISMATCH_PENALTY = 2;
static const int COST_TO_CHOOSE = 1;

- (void)choseCardAtIndex:(NSUInteger)index
{
    Card *card = [self cardAtIndex:index];
    
    if (!card.isMatched) {
        if (card.isChosen) {
            card.chosen = NO;
        } else {
            //mathcing against another card
            for (Card *otherCard in self.cards) {
                if (otherCard.isChosen && !otherCard.isMatched) {
                    int matchScore = [card match:@[otherCard]];
                    if (matchScore) {
                        self.score += matchScore * MATCH_BONUS;
                        card.matched = YES;
                        otherCard.matched = YES;
                    } else {
                        self.score -= MISMATCH_PENALTY;
                        otherCard.chosen = NO;
                    }
                    break;
                }
            }
            self.score -= COST_TO_CHOOSE;
            card.chosen = YES;
        }
    }
}

- (void)choseCardAtIndex:(NSUInteger)index withMode:(int)mode
{
    Card *card = [self cardAtIndex:index];
    if (mode == 0) {
        if (!card.isMatched) {
            if (card.isChosen) {
                card.chosen = NO;
            } else {
                //mathcing against another card
                for (Card *otherCard in self.cards) {
                    if (otherCard.isChosen && !otherCard.isMatched) {
                        int matchScore = [card match:@[otherCard]];
                        if (matchScore) {
                            self.score += matchScore * MATCH_BONUS;
                            card.matched = YES;
                            otherCard.matched = YES;
                        } else {
                            self.score -= MISMATCH_PENALTY;
                            otherCard.chosen = NO;
                        }
                        break;
                    }
                }
                self.score -= COST_TO_CHOOSE;
                card.chosen = YES;
            }
        }
    } else if (mode == 1) {
        if (!card.isMatched) {
            if (card.isChosen) {
                card.chosen = NO;
                [self.currentCards removeObject:card];  //removing the card from the current cards that are queued for matching
            } else {
                if ([self.currentCards count] == 2) {
                    int matchScore = [card match:self.currentCards];
                    if (matchScore) {
                        self.score += matchScore * MATCH_BONUS;
                        card.matched = YES;
                        for (Card *otherCard in self.currentCards) {
                            otherCard.matched = YES;
                        }
                    } else {
                        self.score -= MISMATCH_PENALTY;
                        Card *otherCard =[self.currentCards objectAtIndex:0];
                        otherCard.chosen = NO;
                        [self.currentCards removeObjectAtIndex:0];
                    }
                    [self.currentCards removeAllObjects];
                }
                [self.currentCards addObject:card];
                self.score -= COST_TO_CHOOSE;
                card.chosen = YES;
            }
        }
    }
}

- (Card *)cardAtIndex:(NSUInteger)index
{
    return (index < [self.cards count]) ? self.cards[index] : nil;
}

- (instancetype)init
{
    return nil;
}

@end
