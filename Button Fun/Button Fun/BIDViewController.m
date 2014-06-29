//
//  BIDViewController.m
//  Button Fun
//
//  Created by Lokesh Basu on 28/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "BIDViewController.h"

@implementation BIDViewController

- (IBAction)buttonPressed:(UIButton *)sender
{
    NSString *buttonTitle = [sender titleForState:UIControlStateNormal];
    NSString *labelText = [NSString stringWithFormat:@"%@ button pressed.", buttonTitle];
    _statusLabel.text = labelText;
    
    // styling the text
    NSMutableAttributedString *styledtext = [[NSMutableAttributedString alloc] initWithString:labelText];
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont boldSystemFontOfSize:_statusLabel.font.pointSize]};
    NSRange nameRange = [labelText rangeOfString:buttonTitle];
    [styledtext setAttributes:attributes range:nameRange];
    _statusLabel.attributedText = styledtext;
}
@end
