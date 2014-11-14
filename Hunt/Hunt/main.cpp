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
    int N;
    cin >> N;
    int *arr = new int[N];
    int *outArr = new int[N];
    int *count = new int[100];
    
    for(int i = 0; i < 100; i++)
    {
        count[i] = 0;
    }
    
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        count[tmp] = count[tmp] + 1;
    }
    
    for(int i = 1; i < 100; i++)
    {
        count[i] = count[i-1] + count[i];
    }
    
    for(int i = N-1; i >= 0; i--)
    {
        int finalIndex = count[arr[i]];
        outArr[finalIndex] = arr[i];
        count[arr[i]] = count[arr[i]] -1;
    }
    
    for(int i = 0; i < N; i++)
    {
        cout << outArr[i] << " ";
    }
    
    cout << endl;
    
    
    
    
    
    return 0;
}