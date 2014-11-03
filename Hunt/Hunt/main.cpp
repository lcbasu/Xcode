//
//  main.cpp
//  Hunt
//
//  Created by Lokesh Basu on 03/11/14.
//  Copyright (c) 2014 Lokesh Basu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, T;
    
    cin >> N >> T;
    
    vector<int> width;
    for (int k = 0; k < N; k++)
    {
        int tmp;
        cin >> tmp;
        width.push_back(tmp);
    }
    
    for (int l = 0; l < T; l++)
    {
        int i, j;
        cin >> i >> j;
        vector<int> path;
        path.assign(width.begin()+i, width.begin()+j+1);
        sort(path.begin(), path.end());
        cout << path[0] << endl;
    }
    
    return 0;
}