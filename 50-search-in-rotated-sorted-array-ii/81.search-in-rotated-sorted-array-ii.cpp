#include <iostream>
#include <vector>
#include <algorithm>
/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    bool search(std::vector<int> &nums, int target)
    {
        int k = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                k = i + 1;
                break;
            }
        }

        if (k > 0)
        {
            std::reverse(nums.begin(), nums.begin() + k);
            std::reverse(nums.begin() + k, nums.end());
            std::reverse(nums.begin(), nums.end());
        }

        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int m = s + ((e - s) / 2);
            if (nums[m] == target)
            {
                return true;
            }
            else if (nums[m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        return false;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    std::vector<int> a = {1};
    int target = 3;

    std::cout << obj.search(a, target);
}
