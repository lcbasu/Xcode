//
//  CDTViewController.m
//  CoreDataTutorial
//
//  Created by Lokesh Basu on 20/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CDTViewController.h"

@interface CDTViewController ()

@end

@implementation CDTViewController

// synthesize all the outlet properties
@synthesize textFieldMake;
@synthesize textFieldModel;
@synthesize textFieldColor;

- (NSManagedObjectContext *)managedObjectContext
{
    NSManagedObjectContext *context = nil;
    id delegate = [[UIApplication sharedApplication] delegate];
    if ([delegate performSelector:@selector(managedObjectContext)]) {
        context = [delegate managedObjectContext];
    }
    return context;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)savePressed:(id)sender
{
}

- (IBAction)cancelPressed:(id)sender
{
}



@end
