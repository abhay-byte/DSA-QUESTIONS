#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from Left to Right
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            ++top;

            // Traverse from Top to Bottom
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            --right;

            // Traverse from Right to Left (only if still within bounds)
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    result.push_back(matrix[bottom][i]);
                --bottom;
            }

            // Traverse from Bottom to Top (only if still within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                ++left;
            }
        }

        return result;
    }
};
// @lc code=end

