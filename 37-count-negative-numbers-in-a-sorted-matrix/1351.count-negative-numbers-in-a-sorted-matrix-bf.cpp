#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (grid[i][j] < 0) {
                negativeCnt += (m - i);
                j--;
            } else {
                i++;
            }
        }

        return negativeCnt;

    }
};

// @lc code=end

