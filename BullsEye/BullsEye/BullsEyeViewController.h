//
//  BullsEyeViewController.h
//  BullsEye
//
//  Created by Lokesh Basu on 12/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BullsEyeViewController : UIViewController

@property (strong, nonatomic) IBOutlet UISlider *slider;
@property (strong, nonatomic) IBOutlet UILabel *targetLabel;

- (IBAction)showAlert;

- (IBAction)sliderMoved:(UISlider *)slider;

@end
