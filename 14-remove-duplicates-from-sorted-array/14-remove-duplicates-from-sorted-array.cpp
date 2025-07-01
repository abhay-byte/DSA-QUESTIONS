#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
LeetCode 26. Remove Duplicates from Sorted Array

Time Complexity: O(N), where N is the number of elements in the input vector.
- Each element is visited once.

Space Complexity: O(1), as the operation is performed in-place with constant extra space.

Approach:
- Use two pointers: one to track the position of unique elements, and one to iterate through the array.
- When a new unique element is found, move it next to the last unique element.
- Return the count of unique elements.

Result: Efficient in-place solution.
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int uniqueIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {

            if (nums[i] != nums[uniqueIndex]) {
                ++uniqueIndex;        
                nums[uniqueIndex] = nums[i]; 
            }
        }

        return uniqueIndex + 1;
    }
};
