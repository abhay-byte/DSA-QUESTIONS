#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity: O(1)
Space Complexity: O(1)

Approach: 
Instead of iterating through the interval, we use a mathematical formula to directly calculate the number of odd numbers between l and h (inclusive).
The formula ((h + 1) / 2) - (l / 2) gives the count of odd numbers in the interval [l, h].
This works because (x + 1) / 2 gives the count of odd numbers from 1 to x.

Result: Runtime: 0 ms Memory Usage: 7.7 MB   
Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
*/

class Solution {
public:
    int countOdds(int l, int h) {
        return ((h + 1) / 2) - (l / 2);
    }
};