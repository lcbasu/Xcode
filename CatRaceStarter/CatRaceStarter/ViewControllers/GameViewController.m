//
//  ViewController.m
//  CatRaceStarter
//
//  Created by Kauserali on 30/12/13.
//  Copyright (c) 2013 Raywenderlich. All rights reserved.
//

#import "GameViewController.h"
#import "GameOverViewController.h"
#import "GameScene.h"

@implementation GameViewController

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];

    // Configure the view.
    SKView * skView = (SKView *)self.view;
    skView.showsFPS = YES;
    skView.showsNodeCount = YES;
    
    // Create and configure the scene.
    GameScene * scene = [GameScene sceneWithSize:skView.bounds.size];
    scene.scaleMode = SKSceneScaleModeAspectFill;
    
    scene.gameEndedBlock = ^() {

    };
    
    scene.gameOverBlock = ^(BOOL didWin) {
        GameOverViewController *gameOverViewController = (GameOverViewController*)[self.storyboard instantiateViewControllerWithIdentifier:@"GameOverViewController"];
        gameOverViewController.didWin = didWin;
        [self.navigationController pushViewController:gameOverViewController animated:YES];
    };
    // Present the scene.
    [skView presentScene:scene];
}
@end
