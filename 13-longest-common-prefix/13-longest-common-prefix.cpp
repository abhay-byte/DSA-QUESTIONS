#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
LeetCode 14. Longest Common Prefix

Time Complexity: O(N * M), where N is the number of strings and M is the length of the shortest string.
- Each character of each string is compared at most once.

Space Complexity: O(1), ignoring the space required for the output string.

Approach:
- Start with the first string as the prefix.
- Compare the prefix with each subsequent string, reducing its length as needed.
- Stop early if the prefix becomes empty.

Result: Efficient solution for finding the longest common prefix.
Link: https://leetcode.com/problems/longest-common-prefix/
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j);
            if (prefix.empty()) return "";
        }
        return prefix;
    }
};