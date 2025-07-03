#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
/*
 * Problem: 169. Majority Element (LeetCode)
 *
 * Time Complexity: O(n)
 * - n is the size of the input vector.
 * - We traverse the array once to count occurrences, and once to find the majority.
 *
 * Space Complexity: O(n)
 * - We use an unordered_map to store counts for each unique element.
 *
 * Approach:
 * - Count the frequency of each number using a hash map.
 * - Find the element with the highest frequency (majority element).
 *
 * Link: https://leetcode.com/problems/majority-element/
 */
/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i: nums)
        {
            map[i]++;
        }
        int maxSoFar = INT_MIN;
        int result;
        for (const auto& pair : map) {
            if(pair.second > maxSoFar)
            {
                maxSoFar = pair.second;
                result = pair.first;
            }
        }
        return result;
    }
};
// @lc code=end

