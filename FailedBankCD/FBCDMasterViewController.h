//
//  FBCDMasterViewController.h
//  FailedBankCD
//
//  Created by Lokesh Basu on 28/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FBCDMasterViewController : UITableViewController

@property (nonatomic,strong) NSManagedObjectContext* managedObjectContext;

@end
