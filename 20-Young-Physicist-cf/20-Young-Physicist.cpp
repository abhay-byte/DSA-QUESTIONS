#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: Young Physicist (Codeforces 69A)

Time Complexity: O(n)
- n is the number of vectors.
- Each vector's components are read and summed in O(1) time.

Space Complexity: O(1)
- Only three integers are used to store the sum of x, y, and z components.

Approach:
- Read n vectors (each with x, y, z components).
- Sum all x, y, and z components separately.
- If all sums are zero, the system is in equilibrium; otherwise, it is not.

Link: https://codeforces.com/problemset/problem/69A
*/

int main() {
    int n;
    cin >> n;
    int sum_x = 0, sum_y = 0, sum_z = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }
    if (sum_x == 0 && sum_y == 0 && sum_z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
