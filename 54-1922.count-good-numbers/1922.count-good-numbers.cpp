
#include<iostream>
#include<cmath>
/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 */

 /**
 * @brief Counts the number of "good numbers" of length n.
 * 
 * A "good number" is defined such that:
 * - Digits at even indices (0-based) can be 0, 2, 4, 6, or 8 (5 choices).
 * - Digits at odd indices can be 1, 3, 5, 7, or 9 (4 choices).
 * 
 * Uses modular exponentiation to efficiently compute the result.
 * 
 * Time Complexity: O(log n)
 *   - Due to the recursive modular exponentiation (mod_pow).
 * 
 * Space Complexity: O(log n)
 *   - Due to the recursion stack in mod_pow.
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;

    // Recursive modular exponentiation function
    long long mod_pow(long long base, long long exp) {
        // Base case: any number to the power 0 is 1
        if (exp == 0) return 1;
        // Recursive case: compute half power
        long long half = mod_pow(base, exp / 2);
        long long res = (half * half) % MOD;
        // If exponent is odd, multiply by base once more
        if (exp % 2) res = (res * base) % MOD;
        return res;
    }

    // Counts the number of good numbers of length n
    int countGoodNumbers(long long n) {
        // Even positions can be filled with 5 choices (0,2,4,6,8)
        long long even_positions = (n + 1) / 2;
        // Odd positions can be filled with 4 choices (1,3,5,7,9)
        long long odd_positions = n / 2;
        // Calculate total combinations using modular exponentiation
        long long res = (mod_pow(5, even_positions) * mod_pow(4, odd_positions)) % MOD;
        return res;
    }
};
// @lc code=end
int main()
{
    Solution obj;

    std::cout << obj.countGoodNumbers(1);
}
