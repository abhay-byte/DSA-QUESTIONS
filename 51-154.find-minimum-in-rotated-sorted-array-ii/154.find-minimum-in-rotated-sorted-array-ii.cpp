#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int minSearch(std::vector<int> &nums, int left, int right)
    {
        int minSoFar = 5000;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            minSoFar = std::min(minSoFar,nums[mid]);
            right = mid - 1;
        }
        return minSoFar;
    }
    int findMin(std::vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                k = i + 1;
                break;
            }
        }       
        int min1 = 5001;
        if(k>0)
            min1 = minSearch(nums,0,k - 1);
        int min2 = minSearch(nums,k,nums.size()-1);
        return std::min(min1,min2);
    }
};
// @lc code=end


int main()
{
    Solution obj;
    std::vector<int> a = {1,2,3};
    int target = 0;

    std::cout << obj.findMin(a);
}
