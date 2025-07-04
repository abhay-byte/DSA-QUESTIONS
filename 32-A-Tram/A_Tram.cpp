#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Tram (Codeforces 116A)

Time Complexity: O(n)
- n is the number of stops.
- For each stop, we perform constant time operations.

Space Complexity: O(1)
- Only a few integer variables are used.

Approach:
- Read the number of stops.
- For each stop, read the number of people exiting and entering.
- Update the current capacity and track the maximum capacity reached.

Link: https://codeforces.com/problemset/problem/116/A
*/

int main()
{
    int n;

    cin >> n;

    int capacity = 0;
    int maxSoFar = 0;
    
    for(int i = 0; i<n; i++)
    {
        int enters; int exits;

        cin >> exits;
        cin >> enters;

        capacity  = capacity - exits + enters;

        maxSoFar = max(maxSoFar, capacity);
    }
    cout << maxSoFar << endl;

}