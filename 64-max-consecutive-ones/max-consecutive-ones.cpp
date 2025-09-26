#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxSoFar = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(1 & nums[i])
            {
                cnt++;
            }
            else
            {
                maxSoFar = max(maxSoFar, cnt);
                cnt = 0;
            }
        }
        maxSoFar = max(maxSoFar, cnt);
        return maxSoFar;
        
    }
};