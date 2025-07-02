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
        
    }
};