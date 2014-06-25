//
//  CardGameViewController.m
//  MatchismoV2
//
//  Created by Lokesh Basu on 23/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CardGameViewController.h"
#import "CardMatchingGame.h"
#import "PlayingCardDeck.h"
#import "Card.h"

@interface CardGameViewController ()

@property (strong, nonatomic) Deck *deckOfCards;
@property (nonatomic, strong) CardMatchingGame *game;


@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *cardButtons;


@property (weak, nonatomic) IBOutlet UILabel *scoreLabel;
@property (weak, nonatomic) IBOutlet UISegmentedControl *gameModeSwitchOutlet;

@end

@implementation CardGameViewController

- (CardMatchingGame *)game
{
    if (!_game) _game = [[CardMatchingGame alloc] initWithCardCount:[self.cardButtons count]
                                                          usingDeck:[self createDeck ]];
    return _game;
}

- (Deck *)createDeck
{
    return [[PlayingCardDeck alloc] init];
}


- (IBAction)touchCardButton:(UIButton *)sender
{
    self.gameModeSwitchOutlet.enabled = NO;
    int cardIndex = [self.cardButtons indexOfObject:sender];
    [self.game chooseCardAtIndex:cardIndex];
    [self updateUI];
}

- (void)updateUI
{
    for (UIButton *cardButton in self.cardButtons) {
        int cardIndex = [self.cardButtons indexOfObject:cardButton];
        Card *card = [self.game cardAtIndex:cardIndex];
        [cardButton setTitle:[self titleForCard:card] forState:UIControlStateNormal];
        [cardButton setBackgroundImage:[self backgroundImageForCard:card] forState:UIControlStateNormal];
        cardButton.enabled = !card.isMatched;
    }
    
    self.scoreLabel.text = [NSString stringWithFormat:@"Score: %d", self.game.score];
}

- (NSString *)titleForCard:(Card *)card
{
    return card.isChosen ? card.contents : @"";
}

- (UIImage *)backgroundImageForCard:(Card *)card
{
    return [UIImage imageNamed:card.isChosen ? @"cardfront" : @"cardback"];
}

- (IBAction)resetGame
{
    _game = nil;
    [self resetUI];
}

- (void)resetUI
{
    for (UIButton *cardButton in self.cardButtons) {
        int cardIndex = [self.cardButtons indexOfObject:cardButton];
        Card *card = [self.game cardAtIndex:cardIndex];
        card.chosen = NO;
        card.matched = NO;
        [cardButton setTitle:[self titleForCard:card] forState:UIControlStateNormal];
        [cardButton setBackgroundImage:[self backgroundImageForCard:card] forState:UIControlStateNormal];
        cardButton.enabled = YES;
    }
    self.scoreLabel.text = @"Score: 0";
    
    // enable the game switch at the begining
    self.gameModeSwitchOutlet.enabled = YES;
}
- (IBAction)gameModeSwitch:(UISegmentedControl *)sender
{
    self.game.gameMode = sender.selectedSegmentIndex;
}

@end
