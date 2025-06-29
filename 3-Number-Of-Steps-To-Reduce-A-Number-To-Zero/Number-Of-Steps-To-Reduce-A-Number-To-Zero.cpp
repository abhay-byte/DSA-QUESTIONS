#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity: O(log(n))
Space Complexity: O(1)

Approach:
The function repeatedly divides the number by 2 if it is even,
or subtracts 1 if it is odd, counting the steps until the number becomes zero.

Result: Runtime: 0 ms Memory Usage: 6.1 MB
Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
*/

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num != 0)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
                steps++;
            }
            else if (num % 2 != 0)
            {
                num--;
                steps++;
            }
        }
        return steps;
    }
};