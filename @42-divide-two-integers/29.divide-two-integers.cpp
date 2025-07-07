#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow: only case that overflows 32-bit signed int
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long before abs to avoid overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            // Double temp and multiple while possible
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // Apply sign
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        return isNegative ? -result : result;
    }
};


// @lc code=end

