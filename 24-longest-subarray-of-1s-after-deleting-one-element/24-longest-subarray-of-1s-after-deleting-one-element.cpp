#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
Problem: 24-Longest-Subarray-of-1s-After-Deleting-One-Element (LeetCode 1493)

Time Complexity: O(n)
- n is the number of elements in the input vector.
- The algorithm traverses the array once.

Space Complexity: O(1)
- Only a few integer variables are used for tracking counts.

Approach:
- Use a sliding window to keep track of the number of zeros in the current window.
- Maintain the window such that at most one zero is present (since we can delete one element).
- Update the maximum length found as the window slides.
- Return the maximum length found.

Result: Efficient single-pass solution.
Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        int n = nums.size();

        while (right < n)
        {
            if (nums[right] == 0)
                zeroCount++;
            while (zeroCount > 1)
            {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }
            maxLen = max(maxLen, right - left);
            right++;
        }
        return maxLen;
    }
};
