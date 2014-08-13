//
//  TestSRM2.h
//  TopCoder
//
//  Created by Lokesh Basu on 12/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#ifndef TopCoder_TestSRM2_h
#define TopCoder_TestSRM2_h

void display(int num)
{
    if (num <= 0) {
        return;
    }
    while (num--) {
        cout << "Num: " << num << endl;
    }
}

#endif
