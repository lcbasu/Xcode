//
//  RWTMasterViewController.h
//  ScaryBugs2
//
//  Created by Lokesh Basu on 03/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreData/CoreData.h>

@interface RWTMasterViewController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) NSMutableArray *bugs;

@end
