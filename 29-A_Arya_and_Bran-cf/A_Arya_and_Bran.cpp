#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Keyboard (Codeforces 474A)

Time Complexity: O(m)
- m is the length of the input string.
- For each character, we perform a lookup and output in O(1) time.

Space Complexity: O(1)
- Only a few variables are used; no extra space proportional to input size.

Approach:
- Read the direction ('L' or 'R') and the input string.
- For each character in the input, find its position on the keyboard layout.
- Shift the character left or right depending on the direction and output the result.

Link: https://codeforces.com/problemset/problem/474/A
*/

int main()
{
    int n; int k;
    cin >> n;
    cin >> k;
    int candiesLeft = 0;
    int noOfDays = 0;
    
    for(int i=0; i < n ;i++)
    {
        int temp = 0;
        cin >> temp;
        temp+=candiesLeft;
        if(temp>8)
        {
            temp -=8;
            k -= 8;
            candiesLeft=temp;
            noOfDays++;
        }
        else
        {
            k -= temp;
            noOfDays++;
            candiesLeft = 0;
        }

        if(k<=0)
        {
            cout << noOfDays << endl;
            break;
        }

    }

    if(k>0)
    {
        cout << -1 << endl;
    }
}