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


- (AVAudioPlayer *)setupAudioPlayerWithFile:(NSString *)file type:(NSString *)type
{
    NSString *path = [[NSBundle mainBundle] pathForResource:file ofType:type];
    NSURL *url = [NSURL fileURLWithPath:path];
    
    NSError *error;
    
    AVAudioPlayer *audioPlayer = [[AVAudioPlayer alloc]
                                  initWithContentsOfURL:url
                                  error:&error];
    
    if (!audioPlayer) {
        NSLog(@"%@", [error description]);
    }
    
    return audioPlayer;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    
    //  setup background
    self.view.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"bg_tile.png"]];
    scoreLabel.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"field_score.png"]];
    timerLabel.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"field_time.png"]];
    
    //  setup sound
    buttonBeep = [self setupAudioPlayerWithFile:@"ButtonTap" type:@"wav"];
    secondbeep = [self setupAudioPlayerWithFile:@"SecondBeep" type:@"wav"];
    backgroundMusic = [self setupAudioPlayerWithFile:@"HallOfTheMountainKing" type:@"mp3"];
    
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
    
    //  play sound on tap
    [buttonBeep play];
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
    
    //  play background music
    [backgroundMusic setVolume:0.3];
    [backgroundMusic play];
}

- (void)subtractTime
{
    seconds--;
    timerLabel.text = [NSString stringWithFormat:@"Time : %i", seconds];
    
    //  play second beep
    [secondbeep play];
    
    if (seconds == 0) {
        [timer invalidate];
        
        //  alert view
        
        UIAlertView *stopGame = [[UIAlertView alloc] initWithTitle:@"Time is up!"
                                                           message:[NSString stringWithFormat:@"Your score was %i.", count]
                                                          delegate:self
                                                 cancelButtonTitle:@"Play again."
                                                 otherButtonTitles:@"Fun!", nil];
        [stopGame show];
        
        //  stopping abckground music
        [backgroundMusic stop];
    }
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [self setupGame];
}


@end
