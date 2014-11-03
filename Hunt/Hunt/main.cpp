//
//  main.cpp
//  Hunt
//
//  Created by Lokesh Basu on 03/11/14.
//  Copyright (c) 2014 Lokesh Basu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a = 8;
    
    int b = 9;
    
    a = b;
    
    vector<int> v;
    
    v.push_back(a);
    v.push_back(b);
    
    cout << a << endl;
    
    return 0;
}
