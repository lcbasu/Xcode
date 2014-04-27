//
//  FailedBankDatabase.h
//  FailedBanks
//
//  Created by Lokesh Basu on 27/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface FailedBankDatabase : NSObject {
    sqlite3 *_database;
}

+ (FailedBankDatabase*)database;
- (NSArray *)failedBankInfos;

@end
