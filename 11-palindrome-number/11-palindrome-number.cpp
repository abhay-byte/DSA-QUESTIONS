#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
LeetCode 1920. Build Array from Permutation

Time Complexity: O(N), where N is the length of the input array.
- The function iterates through the array once to build the result.

Space Complexity: O(N), for storing the result vector.

Approach:
- For each index i in the input array, set result[i] = nums[nums[i]].
- Return the result vector.

Result: Runtime: 0 ms, Memory Usage: 20.6 MB
Link: https://leetcode.com/problems/build-array-from-permutation/
*/
class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        int reverse = 0;

        while(x > 0)
        {
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x = x / 10;
        }

        return reverse == original;
    }
};

int main() {
    Solution sol;
    int num = 121;
    if (sol.isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
}