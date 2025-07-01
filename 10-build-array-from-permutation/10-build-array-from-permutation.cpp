#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
LeetCode 1920. Build Array from Permutation

Time Complexity: O(N), where N is the length of the input array.
- The function iterates through the array once to build the result.

Space Complexity: O(N), for storing the result vector.

Approach:
- For each index i in the input array, set result[i] = nums[nums[i]].
- Return the result vector.

Result: Runtime: 0 ms, Memory Usage: 20.6 MB
Link: https://leetcode.com/problems/build-array-from-permutation/
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result(nums.size());

        int cnt = 0;
        for(int i: nums)
        {
            result[cnt] = nums[i];
            cnt++; 
        }
        return result;
    }
};