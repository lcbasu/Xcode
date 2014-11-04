//
//  main.cpp
//  Hunt
//
//  Created by Lokesh Basu on 03/11/14.
//  Copyright (c) 2014 Lokesh Basu. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string str;
        cin >> str;
        int i = 0;
        int j = str.size()-1;
        int operation = 0;
        while(i < j)
        {
            operation += abs(str[i] - str[j]);
            i++;
            j--;
        }
        cout << operation << endl;
    }
    return 0;
}