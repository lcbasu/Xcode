//
//  main.cpp
//  TopCoder
//
//  Created by Lokesh Basu on 12/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <iostream>
#include "TestSRM.h"
#include "TestSRM2.h"
#include <vector>

int main(int argc, const char * argv[])
{
    display();
    cout << "Hello, World!\n";
    display(4);
    
    
    vector<int> vc;
    
    vc.push_back(4);
    vc.push_back(6);
    vc.push_back(2);
    
    sort(vc.begin(), vc.end());
    
    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << endl;
    }
    
    return 0;
}

