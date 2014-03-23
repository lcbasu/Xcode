//
//  Card.h
//  HomeWork
//
//  Created by Lokesh Basu on 23/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Card : NSObject

@property (strong, nonatomic) NSString *contents;

@property (nonatomic, getter = isChosen) BOOL chosen;
@property (nonatomic, getter = isMatched) BOOL matched;

- (int)match:(NSArray *)otherCards;

@end