#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
Problem: A. Free Cash (Codeforces 237A)

Time Complexity: O(n)
- n is the number of time records.
- Each record is processed in O(1) time using a hash map.

Space Complexity: O(n)
- In the worst case, all time records are unique, so the hash map stores up to n entries.

Approach:
- Read n time records (hour and minute).
- Use a hash map to count occurrences of each (hour, minute) pair.
- The answer is the maximum count for any time pair.

Link: https://codeforces.com/problemset/problem/237/A
*/

int main()
{
    int n;
    cin >> n;

    unordered_map<string,int> map;

    for(int i = 0; i < n; i++)
    {
        string str;
        int hr; int min;
        
        cin >> hr;
        cin >> min;

        str = to_string(hr)+":"+to_string(min);

        map[str]++;
    }

    int maxSoFar = 0;
    for(auto pair: map)
    {
        maxSoFar = max(maxSoFar,pair.second);
    }
    cout << maxSoFar << endl;
}