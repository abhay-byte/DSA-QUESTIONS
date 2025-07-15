#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0; int e = nums.size()-1;
        //m = s + ((e-s)/2)
        while(s<=e)
        {
            int m = s + ((e-s)/2);
            if(nums[m] == target)
            {
                return m;
            }
            else if (target > nums[m])
            {
                s = m + 1;
            }
            else if (target < nums[m])
            {
                e = m - 1;
            }
        }
        
        return s;
    }
};
// @lc code=end

int main()
{
    Solution obj;
    vector<int> arr = {1,3,5,6};
    cout << obj.searchInsert(arr,7);
}

