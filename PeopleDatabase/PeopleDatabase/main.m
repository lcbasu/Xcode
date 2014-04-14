//
//  main.m
//  PeopleDatabase
//
//  Created by Lokesh Basu on 14/04/14.
//  Copyright (c) 2014 IIT Roorkee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        char response;
        
        NSMutableArray *contactList = [[NSMutableArray alloc] init];
        
        do {
            Person *newPerson = [[Person alloc] init];
            [newPerson enterInfo];
            [contactList addObject:newPerson];
            NSLog(@"Do you want to enter another name? (y/n)");
            scanf("\n%c", &response);
        } while(response == 'y');
        NSLog(@"Total people in the contact list is %lu.", (unsigned long)[contactList count]);
        NSLog(@"People in the contact list :\n");
        for (Person *singlePerson in contactList) {
            [singlePerson printInfo];
        }
    }
    return 0;
}

