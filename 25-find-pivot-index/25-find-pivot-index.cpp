#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
Problem: 25-Find-Pivot-Index (LeetCode 724)

Time Complexity: O(n)
- n is the number of elements in the input vector.
- The algorithm traverses the array once to compute the total sum, and once more to find the pivot.

Space Complexity: O(1)
- Only a few integer variables are used for tracking sums.

Approach:
- Calculate the total sum of the array.
- Iterate through the array, maintaining a running sum of elements to the left.
- For each index, check if the left sum equals the total sum minus the left sum minus the current element.
- Return the index if found, otherwise return -1.

Result: Efficient single-pass solution after computing total sum.
Link: https://leetcode.com/problems/find-pivot-index/
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumLeft(n, 0), sumRight(n, 0);

        // Compute sumLeft
        for (int i = 1; i < n; ++i) {
            sumLeft[i] = sumLeft[i - 1] + nums[i - 1];
        }

        // Compute sumRight
        for (int i = n - 2; i >= 0; --i) {
            sumRight[i] = sumRight[i + 1] + nums[i + 1];
        }

        // Find pivot index
        for (int i = 0; i < n; ++i) {
            if (sumLeft[i] == sumRight[i]) {
                return i;
            }
        }
        return -1;
    }
};