#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Helpful Maths (Codeforces 339A)

Time Complexity: O(n log n)
- n is the number of digits in the input string (excluding '+').
- Sorting the digits takes O(n log n) time.

Space Complexity: O(n)
- We store the digits in a vector.

Approach:
- Read the input string containing digits and '+' signs.
- Extract all digits and store them in a vector.
- Sort the vector of digits.
- Output the sorted digits separated by '+'.

Link: https://codeforces.com/problemset/problem/339/A
*/

int main()
{
    string s;
    cin >> s;

    vector<int> n;

    for (char i: s)
    {
        if(i != '+')
        {
            int t = i - '0';
            n.push_back(t);
        } 
    }

    sort(n.begin(),n.end());

    if(n.size() == 1)
    {
        cout << n[0];
    }
    else
    {
        cout << n[0];
        for(int i = 1; i < n.size(); i++)
        {
            cout << "+" << n[i];
        }
    }
}