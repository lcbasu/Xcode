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
    int L, R;
    
    cin >> L >> R;
    
    int max = 0;
    
    for (int A = L; A <= R; A++)
    {
        for (int B = A; B <= R; B++)
        {
            int val = A ^ B;
            if (val > max)
            {
                max = val;
            }
        }
    }
    
    cout << max;
    
    return 0;
}