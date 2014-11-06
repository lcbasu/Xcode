#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    
    string s;
    cin>>s;
    
    int arr[26];
    
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        int index = (int)s[i] - 97;
        arr[index] = arr[index] + 1;
    }
    
    int oddCount = 0;
    
    for (int i = 0; i < 26; i++)
    {
        if (arr[i]%2 != 0)
        {
            oddCount++;
        }
    }
    
    
    if(oddCount > 1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
