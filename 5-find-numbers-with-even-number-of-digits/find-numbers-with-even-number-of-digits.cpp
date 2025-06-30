#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity: O(N * log(M)), where N is the number of elements in nums and M is the maximum number in nums.
Space Complexity: O(1)

Approach:
The function iterates through each number in the input vector nums.
For each number, it counts the number of digits by dividing by 10 until the number becomes 0.
If the count of digits is even, it increments the evenCnt counter.
Finally, it returns the total count of numbers with an even number of digits.

Result: Result: Runtime: 0 ms Memory Usage: 13.39 MB
Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCnt = 0;
        for(int n : nums)
        {
            int cnt = 0;
            while(n!=0)
            {
                int temp = n/10;
                n = temp;
                cnt++;
            }
            if (cnt%2 == 0 )
                evenCnt++;
        }
        return evenCnt;
    }
};