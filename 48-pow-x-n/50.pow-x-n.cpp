#include <cstdlib>
#include <iostream>
/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        double result = 1;
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                result = result * x;
            }
            x = x * x;
            N = N / 2;
        }

        return result;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    std::cout << obj.myPow(2.0, -10);
}
