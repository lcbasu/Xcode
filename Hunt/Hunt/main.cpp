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
        long long int K;
        cin >> K;
        long long int a = K/2;
        long long int b = K-a;
        
        cout << a*b << endl;
    }
    return 0;
}