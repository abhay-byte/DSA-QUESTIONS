#include <iostream>
#include <vector>
/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[mid + 1]) {
                // Peak is on the right side
                left = mid + 1;
            } else {
                // Peak is on the left side (including mid)
                right = mid;
            }
        }
        
        return left;
    }
};

int main()
{
    std::vector<int> arr = {3,4,3,2,1};
    Solution obj;

    std::cout << obj.findPeakElement(arr);
}
// @lc code=end

int main()
{
    std::vector<int> arr = {3,4,3,2,1};
    Solution obj;

    std::cout << obj.findPeakElement(arr);
}
// @lc code=end
