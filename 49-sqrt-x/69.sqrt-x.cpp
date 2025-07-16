#include <iostream>
/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int s = 0; int e = x; int ans = 0;

        while(s<=e)
        {
            int m = s + ((e-s)/2);
            if((long long)m*m == x)
            {
                return m;
            }
            else if ((long long)m*m < x)
            {
                ans = m;
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution obj;
    std::cout << obj.mySqrt(4);
}