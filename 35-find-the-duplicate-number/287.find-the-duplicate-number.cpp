#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * Time Complexity: O(n)
 * - Uses a binary search approach on the value range, each pass counts elements in O(n).
 *
 * Space Complexity: O(1)
 * - No extra space is used except for a few variables.
 *
 * Approach:
 * - Use binary search on the range [1, n] (where n = nums.size() - 1).
 * - For each mid, count how many numbers are <= mid.
 * - If count > mid, the duplicate is in the lower half; else, it's in the upper half.
 * - Repeat until left == right, which is the duplicate.
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) count++;
            }
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

