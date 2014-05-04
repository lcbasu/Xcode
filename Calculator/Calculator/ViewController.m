//
//  ViewController.m
//  Calculator
//
//  Created by Lokesh Basu on 04/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize display = _display;
@synthesize userIsInTheMiddleOfEnteringANumber = _userIsInTheMiddleOfEnteringANumber;
@synthesize brain = _brain;
@synthesize operation = _operation;


- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    _display.text = @"0";
}

- (Brain *)brain
{
    if (!_brain) {
        _brain = [[Brain alloc] init];
    }
    return _brain;
}

- (IBAction)digitPressed:(id)sender
{
    NSString *digit = [sender currentTitle];
    
    if ([_display.text isEqualToString:@"0"]) {
        _display.text = @"";
        if (digit == 0) {
            _display.text = @"0";
        }
    }
    if (_userIsInTheMiddleOfEnteringANumber) {
        _display.text = [_display.text stringByAppendingString:digit];
    }
    else {
        _display.text = digit;
        _userIsInTheMiddleOfEnteringANumber = YES;
    }
    
    _display.text = [_display.text stringByAppendingString:digit];
}

- (IBAction)equalPressed
{
    [self.brain getOperand:[self.display.text doubleValue]];
    self.userIsInTheMiddleOfEnteringANumber = NO;
    double result = [self.brain performCalculation:_operation];
    self.display.text = [NSString stringWithFormat:@"%g", result];
}
- (IBAction)operationPressed:(id)sender
{
    _operation = [sender currentTitle];
    
    [self.brain getOperand:[self.display.text doubleValue]];
    self.userIsInTheMiddleOfEnteringANumber = NO;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
