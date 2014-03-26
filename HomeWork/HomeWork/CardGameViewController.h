//
//  CardGameViewController.h
//  HomeWork
//
//  Created by Lokesh Basu on 23/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//
//  Abstract class. All the methods must be implemented in the sub-class of
//  this concrete(or Abstract) class.

#import <UIKit/UIKit.h>
#import "Deck.h"

@interface CardGameViewController : UIViewController


//protected
//for sub-classes
- (Deck *)createDeck;   //abstract


@end
