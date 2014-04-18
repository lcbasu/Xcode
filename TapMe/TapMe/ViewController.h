//
//  ViewController.h
//  TapMe
//
//  Created by Lokesh Basu on 15/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface ViewController : UIViewController<UIAlertViewDelegate> {
    IBOutlet UILabel *scoreLabel;
    IBOutlet UILabel *timerLabel;
    
    NSInteger count;
    NSInteger seconds;
    NSTimer *timer;
    
    
    //  sound
    AVAudioPlayer *buttonBeep;
    AVAudioPlayer *secondbeep;
    AVAudioPlayer *backgroundMusic;
}

- (IBAction)buttonPressed;


@end
