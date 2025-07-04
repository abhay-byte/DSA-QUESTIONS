#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Fancy Fence (Codeforces 270A)

Time Complexity: O(1) per test case
- For each test case, we perform a constant-time calculation.

Space Complexity: O(1)
- Only a few variables are used; no extra space proportional to input size.

Approach:
- For a given angle x, check if there exists a regular polygon whose internal angle is x.
- The formula for the internal angle of a regular polygon: angle = 180 * (n - 2) / n
- Rearranged to find n: n = 360 / (180 - x)
- If n is an integer greater than 2, such a polygon exists.

Link: https://codeforces.com/problemset/problem/270/A
*/

int main()
{
    //30 = (180 * (n - 2)) / n
    // n = 360 / (180 - x)

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        // The formula for the internal angle of a regular polygon: angle = 180 * (n - 2) / n
        // Rearranged to find n: n = 360 / (180 - x)
        if (360 % (180 - x) == 0 && (180 - x) != 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}