//
//  BIDViewController.m
//  Control Fun
//
//  Created by Lokesh Basu on 29/06/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "BIDViewController.h"

@interface BIDViewController ()

@property (weak, nonatomic) IBOutlet UITextField *nameField;
@property (weak, nonatomic) IBOutlet UITextField *numberField;
@property (weak, nonatomic) IBOutlet UILabel *sliderLabel;
@property (weak, nonatomic) IBOutlet UISwitch *leftSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *rightSwitch;

@end

@implementation BIDViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.sliderLabel.text = @"50";
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)textFieldDoneEditing:(id)sender
{
    [sender resignFirstResponder];
}

- (IBAction)backgroundTap:(id)sender
{
    [self.nameField resignFirstResponder];
    [self.numberField resignFirstResponder];
}

- (IBAction)sliderChanged:(UISlider *)sender
{
    int slideValue = lround(sender.value);
    self.sliderLabel.text = [NSString stringWithFormat:@"%d", slideValue];
}
- (IBAction)switchChanged:(UISwitch *)sender
{
    BOOL setting = sender.isOn;
    [self.leftSwitch setOn:setting animated:YES];
    [self.rightSwitch setOn:setting animated:YES];
}

- (IBAction)toggleControls:(UISegmentedControl *)sender
{
}

@end
