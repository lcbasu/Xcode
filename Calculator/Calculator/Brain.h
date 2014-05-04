//
//  Brain.h
//  Calculator
//
//  Created by Lokesh Basu on 04/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Brain : NSObject

- (void)getOperand:(double)operand;
- (double)performCalculation:(NSString *)operation;

@property (nonatomic, strong) NSMutableArray *operand;

@end
