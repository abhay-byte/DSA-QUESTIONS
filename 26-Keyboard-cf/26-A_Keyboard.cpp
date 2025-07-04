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
    string keyboard = "qwertyuiop\nasdfghjkl;\nzxcvbnm,./";
    
    char direction;
    string input;
    cin >> direction >> input;

    int shift = (direction == 'R') ? -1 : 1;
    for (char c : input) {
        size_t pos = keyboard.find(c);
        if (pos != string::npos) {
            cout << keyboard[pos + shift];
        }
    }
    cout << endl;
}
