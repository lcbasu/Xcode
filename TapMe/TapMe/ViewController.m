//
//  ViewController.m
//  TapMe
//
//  Created by Lokesh Basu on 15/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    //  setup and start the game
    [self setupGame];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)buttonPressed
{
    count++;
    scoreLabel.text = [NSString stringWithFormat:@"Score\n%i", count];
}

//  game setup
- (void)setupGame
{
    seconds = 5;
    count = 0;
    
    timerLabel.text = [NSString stringWithFormat:@"Time : %i", seconds];
    scoreLabel.text = [NSString stringWithFormat:@"Score\n%i", count];
    
    timer = [NSTimer scheduledTimerWithTimeInterval:1.0f
                                             target:self
                                           selector:@selector(subtractTime)
                                           userInfo:nil
                                            repeats:YES];
}

- (void)subtractTime
{
    seconds--;
    timerLabel.text = [NSString stringWithFormat:@"Time : %i", seconds];
    
    if (seconds == 0) {
        [timer invalidate];
        
        //  alert view
        
        UIAlertView *stopGame = [[UIAlertView alloc] initWithTitle:@"Time is up!"
                                                           message:[NSString stringWithFormat:@"Your score was %i.", count]
                                                          delegate:self
                                                 cancelButtonTitle:@"Play again."
                                                 otherButtonTitles:@"Fun!", nil];
        [stopGame show];
    }
}



@end
