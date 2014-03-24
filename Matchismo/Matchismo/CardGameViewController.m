//
//  CardGameViewController.m
//  Matchismo
//
//  Created by Lokesh Basu on 19/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CardGameViewController.h"
#import "PlayingCardDeck.h"
#import "CardMatchingGame.h"

@interface CardGameViewController ()
@property (strong, nonatomic) Deck *deck;
@property (nonatomic, strong) CardMatchingGame *game;
@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *cardButtons;
@property (weak, nonatomic) IBOutlet UILabel *scoreLabel;
@property (weak, nonatomic) IBOutlet UISegmentedControl *gameMode;
@property (nonatomic) int currentMode;
@end

@implementation CardGameViewController

- (int)currentMode
{
    return _currentMode;
}


- (CardMatchingGame *)game
{
    if(!_game) _game = [[CardMatchingGame alloc] initWithCardCount:[self.cardButtons count] usingDeck:[self createDeck]];
    self.currentMode = 0;
    return _game;
}


- (Deck *)createDeck
{
    return [[PlayingCardDeck alloc] init];
}


- (IBAction)touchCardButon:(UIButton *)sender
{
    int cardIndex = [self.cardButtons indexOfObject:sender];
    [self.game choseCardAtIndex:cardIndex withMode:self.currentMode];
    //[self.game choseCardAtIndex:cardIndex];
    [self updateUI];
}

- (void)updateUI
{
    for (UIButton *cardButton in self.cardButtons) {
        int cardIndex = [self.cardButtons indexOfObject:cardButton];
        Card *card = [self.game cardAtIndex:cardIndex];
        [cardButton setTitle:[self titleForCard:card]
                    forState:UIControlStateNormal];
        [cardButton setBackgroundImage:[self backgroundImageForCard:card]
                              forState:UIControlStateNormal];
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

- (IBAction)replay:(UIButton *)sender
{
    _game = nil;
    [self updateUI];
}

- (IBAction)changeGameMode:(UISegmentedControl *)sender
{
    switch (sender.selectedSegmentIndex) {
        case 0:
            //two card matching game
            NSLog(@"Two cards matching game");
            [self updateMode:0];
            NSLog(@"Game mode : %d", self.currentMode);
            _game = nil;
            [self updateUI];
            break;
        case 1:
            //three card matching game
            NSLog(@"Three cards matching game");
            [self updateMode:1];
            NSLog(@"Game mode : %d", self.currentMode);
            _game = nil;
            [self updateUI];
        default:
            _game = nil;
            [self updateUI];
            break;
    }
}


- (void)updateMode:(int)mode
{
    self.currentMode = mode;
}

@end
