//
//  ViewController.m
//  DynamicsPlayground
//
//  Created by Lokesh Basu on 16/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <UICollectionViewDelegate>
{
    
    UIDynamicAnimator* _animator;
    UIGravityBehavior* _gravity;
    UICollisionBehavior* _collision;
}

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // making a square
    
    UIView *square = [[UIView alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
    square.backgroundColor = [UIColor redColor];
    [self.view addSubview:square];
    
    // gravity and animation
    
    _animator = [[UIDynamicAnimator alloc] initWithReferenceView:self.view];
    _gravity = [[UIGravityBehavior alloc] initWithItems:@[square]];
    [_animator addBehavior:_gravity];
    
    // barrier for the square box
    
    UIView *barrier = [[UIView alloc] initWithFrame:CGRectMake(0, 300, 130, 20)];
    barrier.backgroundColor = [UIColor greenColor];
    [self.view addSubview:barrier];
    
    // setting boundaries for collision
    
    _collision = [[UICollisionBehavior alloc] initWithItems:@[square]];
    _collision.collisionDelegate = self;
    _collision.translatesReferenceBoundsIntoBoundary = YES;
    [_animator addBehavior:_collision];
    
    // adding invisible boundary
    
    CGPoint rightEdge = CGPointMake(barrier.frame.origin.x + barrier.frame.size.width, barrier.frame.origin.y);
    [_collision addBoundaryWithIdentifier:@"barrier" fromPoint:barrier.frame.origin toPoint:rightEdge];
    
    // behind the scene of collision
    
//    _collision.action = ^{
//        NSLog(@"%@, %@",
//              NSStringFromCGAffineTransform(square.transform),
//              NSStringFromCGPoint(square.center));
//    };
    
    
    // configuring item properties
    
    UIDynamicItemBehavior *itemBehaviour = [[UIDynamicItemBehavior alloc] initWithItems:@[square]];
    itemBehaviour.elasticity = 0.6;
    [_animator addBehavior:itemBehaviour];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)collisionBehavior:(UICollisionBehavior *)behavior beganContactForItem:(id<UIDynamicItem>)item
   withBoundaryIdentifier:(id<NSCopying>)identifier atPoint:(CGPoint)p {
    NSLog(@"Boundary contact occurred - %@", identifier);
    
    UIView *view = (UIView *)item;
    view.backgroundColor = [UIColor yellowColor];
    [UIView animateWithDuration:0.3 animations:^{
        view.backgroundColor = [UIColor redColor];
    }];
}

@end
