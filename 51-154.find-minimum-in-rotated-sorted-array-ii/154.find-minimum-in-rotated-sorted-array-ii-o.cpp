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
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                // nums[mid] == nums[right], can't decide → shrink right
                right--;
            }
        }

        return nums[left];
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
