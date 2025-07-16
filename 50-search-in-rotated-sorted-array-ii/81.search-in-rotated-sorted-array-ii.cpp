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
    bool binarySearch(std::vector<int> &nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
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

        bool left = binarySearch(nums, 0, k - 1, target);
        bool right = binarySearch(nums, k, nums.size() - 1, target);
        return left || right;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    std::vector<int> a = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    std::cout << obj.search(a, target);
}
