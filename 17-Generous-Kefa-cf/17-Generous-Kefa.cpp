#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
Problem: Generous Kefa (Codeforces 827A)

Time Complexity: O(n log n)
- Sorting the string of length n takes O(n log n).
- The subsequent loop is O(n).

Space Complexity: O(1)
- Only a few variables are used; no extra data structures proportional to input size.

Approach:
- Sort the string to group identical characters together.
- Count the maximum number of occurrences of any character.
- If any character appears more than k times, output "NO"; otherwise, output "YES".

Link: https://codeforces.com/problemset/problem/827/A
*/

void KefaFriendsHappy(int n, int k, string s)
{
    sort(s.begin(),s.end());

    char temp = s[0];
    int maxSoFar = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(temp == s[i])
        {
            count++;
        }
        else{
            maxSoFar = max(maxSoFar,count);
            temp = s[i];
            count = 1;
        }
    }

    maxSoFar = max(maxSoFar,count);

    if(maxSoFar > k)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    int n; int k; string s;

    cin >> n;
    cin >> k;
    cin >> s;

    KefaFriendsHappy(n,k,s);

}