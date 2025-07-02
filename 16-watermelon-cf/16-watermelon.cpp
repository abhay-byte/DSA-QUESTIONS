#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Problem: Watermelon (Codeforces 4A)

Time Complexity: O(1)
- Only a single integer is checked.

Space Complexity: O(1)
- No extra space used.

Approach:
- Check if the input weight is even and greater than 2.
- If so, output "YES", otherwise output "NO".

Link: https://codeforces.com/problemset/problem/4/A
*/

void CheckEvenWeightWatermelon(int weight)
{
    if(weight%2 == 0 && weight>2)
    {

        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    int weightOfWatermelon;

    cin >> weightOfWatermelon;

    CheckEvenWeightWatermelon(weightOfWatermelon);
}