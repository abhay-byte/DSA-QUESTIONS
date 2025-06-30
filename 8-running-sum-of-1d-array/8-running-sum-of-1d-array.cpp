#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Time Complexity: O(N), where N is the length of the input array.
- The function iterates through the array once, maintaining a running sum.

Space Complexity: O(N), for storing the result vector of running sums.

Approach:
- Initialize a sum variable to 0.
- Iterate through the input array, adding each element to the sum.
- Append the current sum to the result vector.
- Return the result vector containing the running sums.

Result: Runtime: 0 ms, Memory Usage: 12.6 MB
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> result;
        int sum = 0;
        for(int i: nums)
        {
            sum+=i;
            result.push_back(sum);
        }
        return result;
    }
};