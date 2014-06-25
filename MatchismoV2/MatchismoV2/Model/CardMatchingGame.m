//
//  CardMatchingGame.m
//  MatchismoV2
//
//  Created by Lokesh Basu on 24/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CardMatchingGame.h"

@interface CardMatchingGame()

@property (nonatomic, readwrite) NSInteger score;
@property (nonatomic, strong) NSMutableArray *cards; // of Card class
@property (nonatomic, strong) NSMutableArray *arrayOfCardsToMatch;
@end

@implementation CardMatchingGame

- (NSMutableArray *)arrayOfCardsToMatch
{
    if (!_arrayOfCardsToMatch) _arrayOfCardsToMatch = [[NSMutableArray alloc] init];
    return _arrayOfCardsToMatch;
}

- (NSMutableArray *)cards
{
    if (!_cards) _cards = [[NSMutableArray alloc] init];
    return _cards;
}

- (instancetype)initWithCardCount:(NSUInteger)count usingDeck:(Deck *)deck
{
    self = [super init]; // super's designated initializer
    
    if (self) {
        for (int i = 0; i < count; i++) {
            Card *card = [deck drawrandomcard];
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

- (Card *)cardAtIndex:(NSUInteger)index
{
    return (index < [self.cards count]) ? self.cards[index] : nil;
}


- (void)chooseCardAtIndex:(NSInteger)index
{
    Card *card = [self cardAtIndex:index];
    
    if (self.gameMode == 0) {
        if (!card.isMatched) {
            if (card.isChosen) {
                card.chosen = NO;
            } else {
                // match against anothe chosen card, as only two card matching game
                for (Card *othercard in self.cards) {
                    if (othercard.isChosen && !othercard.isMatched) {
                        int matchScore = [card match:@[othercard]];
                        if (matchScore) {
                            self.score += matchScore * MATCH_BONUS;
                            othercard.matched = YES;
                            card.matched = YES;
                        } else {
                            self.score -= MISMATCH_PENALTY;
                            othercard.chosen = NO;
                        }
                        break; // can choose only two cards
                    }
                }
                self.score -= COST_TO_CHOOSE;
                card.chosen = YES;
            }
        }
    } else if (self.gameMode == 1) {
        if (!card.isMatched) {
            if (card.isChosen) {
                card.chosen = NO;
            } else {
                Card *firstcard = nil;
                Card *secondCard = nil;
                for (Card *otherCard in self.cards) {
                    if (otherCard.isChosen && !otherCard.isMatched) {
                        if (firstcard == nil) {
                            firstcard = otherCard;
                        } else if (secondCard == nil) {
                            secondCard = otherCard;
                        } else if (firstcard != nil && secondCard != nil) {
                            int matchScore = [card match:@[firstcard, secondCard]];
                            if (matchScore) {
                                self.score += matchScore * MATCH_BONUS;
                                firstcard.matched = YES;
                                secondCard.matched = YES;
                                card.matched = YES;
                            } else {
                                self.score -= MISMATCH_PENALTY;
                                firstcard.chosen = NO;
                                secondCard.chosen = NO;
                            }
                            break;
                        }
                    }
                }
                firstcard = nil;
                secondCard = nil;
                self.score -= COST_TO_CHOOSE;
                card.chosen = YES;
            }
        }
    }
}


@end
