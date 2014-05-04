//
//  ViewController.h
//  Calculator
//
//  Created by Lokesh Basu on 04/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Brain.h"

@interface ViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *display;

@property (nonatomic) BOOL userIsInTheMiddleOfEnteringANumber;
@property (nonatomic, strong) Brain *brain;
@property (nonatomic, weak) NSString *operation;

@end
