//
//  srm602_div2_250.h
//  TopCoder
//
//  Created by Lokesh Basu on 14/08/14.
//  Copyright (c) 2014 Samsung. All rights reserved.
//

#ifndef TopCoder_srm602_div2_250_h
#define TopCoder_srm602_div2_250_h


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

class TypoCoderDiv2
{
public:
    int count(vector <int> rating)
    {
        int count = 0;
        for (int i = 0; i < rating.size()-1; i++) {
            if (((rating[i] < 1200) && (rating[i+1] >= 1200)) || ((rating[i] >= 1200) && (rating[i+1] < 1200))) {
                count++;
            }
        }
        return count;
    }
};


#endif
