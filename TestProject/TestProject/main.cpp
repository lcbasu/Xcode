//
//  main.cpp
//  TestProject
//
//  Created by Lokesh Basu on 12/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int i = 4;
    while (i--) {
        int a;
        cin >> a;
        int b;
        cin >> b;
        cout << "Output: ";
        cout << a*b*6 << endl;
    }
    return 0;
}

