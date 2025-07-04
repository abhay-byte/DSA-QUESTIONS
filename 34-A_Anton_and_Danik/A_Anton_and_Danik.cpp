#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Anton and Danik (Codeforces 734A)

Time Complexity: O(n)
- n is the length of the input string.
- We iterate through the string once.

Space Complexity: O(1)
- Only counters for 'A' and 'D' are used.

Approach:
- Read the number of games and the result string.
- Count the number of 'A' (Anton wins) and 'D' (Danik wins).
- Compare the counts and print the winner or "Friendship" if tied.

Link: https://codeforces.com/problemset/problem/734/A
*/

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int a = count(s.begin(), s.end(), 'A');
    int d = n - a;
    if (a > d)
        cout << "Anton" << endl;
    else if (d > a)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}