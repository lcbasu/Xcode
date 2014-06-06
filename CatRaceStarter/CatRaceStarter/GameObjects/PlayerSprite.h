//
//  PlayerSprite.h
//  CatRaceStarter
//
//  Created by Kauserali on 30/12/13.
//  Copyright (c) 2013 Raywenderlich. All rights reserved.
//

NS_ENUM(NSUInteger, PlayerSpriteType) {
    kPlayerSpriteDog,
    kPlayerSpriteKid
};

@interface PlayerSprite : SKSpriteNode

@property (nonatomic, readonly) enum PlayerSpriteType playerType;
@property (nonatomic, readonly) SKAction *moveAnimation;

- (instancetype)initWithType:(enum PlayerSpriteType)playerType;
- (void)moveForward;
@end
