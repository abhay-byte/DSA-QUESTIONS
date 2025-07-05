#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m)); // notice n x m

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};

// @lc code=end

