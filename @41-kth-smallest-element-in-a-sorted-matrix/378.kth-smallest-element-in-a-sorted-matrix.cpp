#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);

            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int count = 0, i = n - 1, j = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return count;
    }
};

// @lc code=end

