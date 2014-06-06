//
//  GameOverViewController.m
//  CatRaceStarter
//
//  Created by Kauserali on 30/12/13.
//  Copyright (c) 2013 Raywenderlich. All rights reserved.
//

#import "GameOverViewController.h"
#import "GameNavigationController.h"

@interface GameOverViewController ()
@property (nonatomic, weak) IBOutlet UILabel *outcomeLabel;
@end

@implementation GameOverViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [_outcomeLabel setText:_didWin ? @"You Won!" : @"You Loose!"];
}

- (IBAction)restartButtonPressed:(id)sender {
    UIWindow *window = self.view.window;

    GameNavigationController *gameNavController = [self.storyboard instantiateViewControllerWithIdentifier:@"GameNavigationController"];
    window.rootViewController = gameNavController;
}
@end
