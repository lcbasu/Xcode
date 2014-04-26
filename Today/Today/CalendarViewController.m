//
//  TodaySecondViewController.m
//  Today
//
//  Created by Lokesh Basu on 17/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "CalendarViewController.h"
#import <EventKit/EventKit.h>
#import <EventKitUI/EventKitUI.h>

@interface CalendarViewController () <EKEventEditViewDelegate>

// EKEventStore instance associated with the current Calendar application
@property (nonatomic, strong) EKEventStore *eventStore;

// Default calendar associated with the above event store
@property (nonatomic, strong) EKCalendar *defaultCalendar;

// Array of all events happening within the next 24 hours
@property (nonatomic, strong) NSMutableArray *eventsList;

// Used to add events to Calendar
@property (weak, nonatomic) IBOutlet UIBarButtonItem *addButton;

@end

@implementation CalendarViewController

#pragma mark - View lifecycle


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    //  calendar events
    
    // Initialize the event store
	self.eventStore = [[EKEventStore alloc] init];
    
    // Initialize the events list
	self.eventsList = [[NSMutableArray alloc] initWithCapacity:0];
    
}

-(void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    // Check whether we are authorized to access Calendar
    [self checkEventStoreAccessForCalendar];
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
    return [self.eventsList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];

    cell.textLabel.text = [[self.eventsList objectAtIndex:indexPath.row] title];
    
    return cell;
}

#pragma mark - Access Calendar

// Check the authorization status of our application for Calendar
-(void)checkEventStoreAccessForCalendar
{
    EKAuthorizationStatus status = [EKEventStore authorizationStatusForEntityType:EKEntityTypeEvent];
    
    switch (status)
    {
            // Update our UI if the user has granted access to their Calendar
        case EKAuthorizationStatusAuthorized: [self accessGrantedForCalendar];
            break;
            // Prompt the user for access to Calendar if there is no definitive answer
        case EKAuthorizationStatusNotDetermined: [self requestCalendarAccess];
            break;
            // Display a message if the user has denied or restricted access to Calendar
        case EKAuthorizationStatusDenied:
        case EKAuthorizationStatusRestricted:
        {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Privacy Warning" message:@"Permission was not granted for Calendar"
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
            [alert show];
        }
            break;
        default:
            break;
    }
}


// Prompt the user for access to their Calendar
-(void)requestCalendarAccess
{
    [self.eventStore requestAccessToEntityType:EKEntityTypeEvent completion:^(BOOL granted, NSError *error)
     {
         if (granted)
         {
             CalendarViewController * __weak weakSelf = self;
             // Let's ensure that our code will be executed from the main queue
             dispatch_async(dispatch_get_main_queue(), ^{
                 // The user has granted access to their Calendar; let's populate our UI with all events occuring in the next 24 hours.
                 [weakSelf accessGrantedForCalendar];
             });
         }
     }];
}


// This method is called when the user has granted permission to Calendar
-(void)accessGrantedForCalendar
{
    // Let's get the default calendar associated with our event store
    self.defaultCalendar = self.eventStore.defaultCalendarForNewEvents;
    // Enable the Add button
    self.addButton.enabled = YES;
    // Fetch all events happening in the next 24 hours and put them into eventsList
    self.eventsList = [self fetchEvents];
    // Update the UI with the above events
    [self.tableView reloadData];
}


#pragma mark - Fetch events

// Fetch all events happening in the next 24 hours
- (NSMutableArray *)fetchEvents
{
    NSDate *startDate = [NSDate date];
    
    //Create the end date components
    NSDateComponents *tomorrowDateComponents = [[NSDateComponents alloc] init];
    tomorrowDateComponents.day = 1;
	
    NSDate *endDate = [[NSCalendar currentCalendar] dateByAddingComponents:tomorrowDateComponents
                                                                    toDate:startDate
                                                                   options:0];
	// We will only search the default calendar for our events
	NSArray *calendarArray = [NSArray arrayWithObject:self.defaultCalendar];
    
    // Create the predicate
	NSPredicate *predicate = [self.eventStore predicateForEventsWithStartDate:startDate
                                                                      endDate:endDate
                                                                    calendars:calendarArray];
	
	// Fetch all events that match the predicate
	NSMutableArray *events = [NSMutableArray arrayWithArray:[self.eventStore eventsMatchingPredicate:predicate]];
    
	return events;
}

#pragma mark - EKEventEditViewDelegate

// Overriding EKEventEditViewDelegate method to update event store according to user actions.
- (void)eventEditViewController:(EKEventEditViewController *)controller
		  didCompleteWithAction:(EKEventEditViewAction)action
{
    CalendarViewController * __weak weakSelf = self;
	// Dismiss the modal view controller
    [self dismissViewControllerAnimated:YES completion:^
     {
         if (action != EKEventEditViewActionCanceled)
         {
             dispatch_async(dispatch_get_main_queue(), ^{
                 // Re-fetch all events happening in the next 24 hours
                 weakSelf.eventsList = [self fetchEvents];
                 // Update the UI with the above events
                 [weakSelf.tableView reloadData];
             });
         }
     }];
}


// Set the calendar edited by EKEventEditViewController to our chosen calendar - the default calendar.
- (EKCalendar *)eventEditViewControllerDefaultCalendarForNewEvents:(EKEventEditViewController *)controller
{
	return self.defaultCalendar;
}

@end
