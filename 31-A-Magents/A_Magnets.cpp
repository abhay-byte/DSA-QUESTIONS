#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Magnets (Codeforces 344A)

Time Complexity: O(n)
- n is the number of magnets.
- We iterate through the list once to count the groups.

Space Complexity: O(n)
- We store all magnet states in a vector.

Approach:
- Read the number of magnets and their orientations.
- Count the number of groups by checking when the orientation changes.

Link: https://codeforces.com/problemset/problem/344/A
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> magnetOrder;

    for(int i=0; i < n; i++)
    {
        string t;
        cin >> t;
        magnetOrder.push_back({t[0],t[1]});
    }

    int groups = 1;
    int prevState = magnetOrder[0][0];
    for(vector<char> pair: magnetOrder)
    {
        if(pair[0] == prevState)
        {
            continue;
        }
        prevState = pair[0];
        groups++;
    }

    cout << groups << endl;
}