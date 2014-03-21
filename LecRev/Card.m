//
//  Card.m
//  Matchismo
//
//  Created by Lokesh Basu on 21/03/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import "Card.h"

@interface Card()

@end

@implementation Card

// @synthesize contents = _contents;

// - (NSString *)contents
// {
// 	return _contents;
// }

// - (void)setContents:(NSString *)contents
// {
// 	_contents = contents;
// }

// @synthesize chosen = _chosen;
// @synthesize matched = _matched;


// //without custom getter names
// - (BOOL)chosen
// {
// 	return _chosen;
// }

// - (void)setChosen:(BOOL)chosen
// {
// 	_chosen = chosen;
// }

// - (BOOL)matched
// {
// 	return _matched;
// }

// -(void)setMatched:(BOOL)matched
// {
// 	_matched = matched;
// }

// //with custom getter names
// - (BOOL)isChosen
// {
// 	return _chosen;
// }

// - (void)setChosen:(BOOL)chosen
// {
// 	_chosen = chosen;
// }

// - (BOOL)isMatched
// {
// 	return _matched;
// }

// -(void)setMatched:(BOOL)matched
// {
// 	_matched = matched;
// }

- (int)matched:(NSArray *)otherCards
{
	int score = 0;

	for(Card *card in otherCards) {
		if([card.contents isEqualToString:self.contents]) {
			score = 1;
		}
	}

	return score;
}

@end
