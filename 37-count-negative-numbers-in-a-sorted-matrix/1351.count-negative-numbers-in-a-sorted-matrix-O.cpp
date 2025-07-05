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

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]<0)
                {
                    negativeCnt += (n-j); 
                    break;
                }
            }
        }

        return negativeCnt;

    }
};

// @lc code=end

