//
//  TodayFirstViewController.m
//  Today
//
//  Created by Lokesh Basu on 17/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "ReminderViewController.h"

@interface ReminderViewController ()

@end

@implementation ReminderViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.mainArray = [[NSMutableArray alloc] initWithObjects:@"R", @"E", @"M", @"I", @"N", @"D", @"E", @"R", @"S", nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//  table view code

#pragma mark - Table View

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.mainArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    
    
    NSString *object = self.mainArray[indexPath.row];
    cell.backgroundColor = [UIColor whiteColor];
    cell.textLabel.text = object;
    
    return cell;
}

@end
