//
//  srm601_div2_250.h
//  TopCoder
//
//  Created by Lokesh Basu on 13/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#ifndef TopCoder_srm601_div2_250_h
#define TopCoder_srm601_div2_250_h

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctype.h>
#include <math.h>
#include <limits>	// numeric_limits<int>::max() similarly for other

using namespace std;

class WinterAndMandarins
{
public:
    int getNumber(vector<int> bags, int K)
    {
        sort(bags.begin(), bags.end());
        
        int min = 0;
        
        for (int i = 0; i < bags.size()-1; i++)
        {
            if (min < (bags[i] - bags[i+1])) {
                min = bags[i] - bags[i+1];
            }
        }
        return min;
    }
};

#endif
