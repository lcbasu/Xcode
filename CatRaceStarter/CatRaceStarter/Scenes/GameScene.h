//
//  MyScene.h
//  CatRaceStarter
//

//  Copyright (c) 2013 Raywenderlich. All rights reserved.
//

@interface GameScene : SKScene
@property (nonatomic, copy) void (^gameOverBlock)(BOOL didWin);
@property (nonatomic, copy) void (^gameEndedBlock)();
@end
