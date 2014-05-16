//
//  ViewController.m
//  DynamicsPlayground
//
//  Created by Lokesh Basu on 16/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () {
    
    UIDynamicAnimator* _animator;
    UIGravityBehavior* _gravity;
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
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
