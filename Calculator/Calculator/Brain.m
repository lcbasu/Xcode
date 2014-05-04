//
//  Brain.m
//  Calculator
//
//  Created by Lokesh Basu on 04/05/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Brain.h"

@implementation Brain

@synthesize operand = _operand;

- (NSMutableArray *)operand
{
    if (!_operand) {
        _operand = [[NSMutableArray alloc] init];
    }
    return _operand;
}

- (void)getOperand:(double)operand
{
    NSNumber *operandObject = [NSNumber numberWithDouble:operand];
    [self.operand addObject:operandObject];
}

- (double)setOperand
{
    NSNumber *operandEntry = [self.operand lastObject];
    if (operandEntry) {
        [self.operand removeLastObject];
    }
    return [operandEntry doubleValue];
}

- (double)performCalculation:(NSString *)operation
{
    double result = 0;
    
    if ([operation isEqualToString:@"+"]) {
        result = [self setOperand] + [self setOperand];
    }
    
    else if ([operation isEqualToString:@"-"]) {
        double subtracthend = [self setOperand];
        result = [self setOperand] - subtracthend;
    }
    
    else if ([operation isEqualToString:@"*"]) {
        result = [self setOperand] * [self setOperand];
    }
    
    else if ([operation isEqualToString:@"/"]) {
        double divisor = [self setOperand];
        result = [self setOperand] / divisor;
    }
    [self getOperand:result];
    
    return result;
}

@end
