#include <iostream>
#include <vector>
using namespace std;
/*
Time Complexity: O(n)
Space Complexity: O(1)

Approach: 
We iterate from the lower bound (low) to the upper bound (high) of the interval.
For each number in this range, we check if it is odd by using the modulo operator (i % 2 != 0).
If the number is odd, we increment the count.
Finally, we return the total count of odd numbers found in the interval.

Result: Runtime: 1672ms ms Memory Usage: 7.83 MB   
Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
*/
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
    for(int i = low; i <= high; i++) {
		if(i % 2 != 0){
            count++;
		}
	}
    return count;
    }
};