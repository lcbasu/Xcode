//
//  DropitViewController.m
//  Dropit
//
//  Created by Lokesh Basu on 31/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "DropitViewController.h"

@interface DropitViewController ()
@property (weak, nonatomic) IBOutlet UIView *gameView;
@property (strong, nonatomic) UIDynamicAnimator *animator;
@property (strong, nonatomic) UIGravityBehavior *gravity;
@end

@implementation DropitViewController

static const CGSize DROP_SIZE = { 40, 40 };

- (UIDynamicAnimator *)animator
{
    if (!_animator) {
        _animator = [[UIDynamicAnimator alloc] initWithReferenceView:self.gameView];
    }
    return _animator;
}

- (UIGravityBehavior *)gravity
{
    if (!_gravity) {
        _gravity = [[UIGravityBehavior alloc] init];
        _gravity.magnitude = 0.9;
        [self.animator addBehavior:_gravity];
    }
    return _gravity;
}

- (IBAction)tap:(UITapGestureRecognizer *)sender
{
    [self drop];
}

- (void)drop
{
    CGRect frame;
    frame.origin = CGPointZero;
    frame.size = DROP_SIZE;
    int x = (arc4random() % (int)self.gameView.bounds.size.width) / DROP_SIZE.width;
    frame.origin.x = x * DROP_SIZE.width;
    
    UIView *dropView = [[UIView alloc] initWithFrame:frame];
    dropView.backgroundColor = [self randomColor];
    [self.gameView addSubview:dropView];
    
    [self.gravity addItem:dropView];
}

- (UIColor *)randomColor
{
    switch (arc4random()%5) {
        case 0:
            return [UIColor greenColor];
            break;
        case 1:
            return [UIColor blueColor];
            break;
        case 2:
            return [UIColor orangeColor];
            break;
        case 3:
            return [UIColor redColor];
            break;
        case 4:
            return [UIColor purpleColor];
            break;
        default:
            break;
    }
    return [UIColor blackColor];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
