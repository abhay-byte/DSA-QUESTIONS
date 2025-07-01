#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Time Complexity: O(N^2), where N is the length of the input array.
- For each element, the function iterates through the entire array to count how many numbers are smaller.

Space Complexity: O(N), for storing the result vector.

Approach:
- For each number in the input array, count how many numbers in the array are smaller than it.
- Store the count for each number in the result vector.
- Return the result vector containing the counts.

Result: Runtime: 0 ms, Memory Usage: 14.36 MB
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        for (int i: nums)
        {
            int val = 0;
            for(int j: nums)
            {
                if(i>j)
                {
                    val++;
                }
            }
            result.push_back(val);
        }
        return result;
    }
};