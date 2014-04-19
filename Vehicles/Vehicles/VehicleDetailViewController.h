//
//  DetailViewController.h
//  Vehicles
//
//  Created by Transferred on 9/8/13.
//  Copyright (c) 2013 Designated Nerd Software. All rights reserved.
//

#import <UIKit/UIKit.h>

//Forward declaration of a class to be imported in the .m file
@class Vehicle;

@interface VehicleDetailViewController : UIViewController

@property (strong, nonatomic) Vehicle *detailVehicle;

@end
