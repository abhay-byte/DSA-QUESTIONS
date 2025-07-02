#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
Problem: 23-Largest-Number (LeetCode 179)

Time Complexity: O(n log n)
- n is the number of elements in the input vector.
- Sorting the numbers with a custom comparator dominates the complexity.

Space Complexity: O(n)
- Additional space is used to store the string representations of the numbers.

Approach:
- Convert all integers to strings.
- Sort the strings using a custom comparator so that the concatenation of the result forms the largest number.
- Concatenate the sorted strings.
- Handle the case where the result is all zeros.

Result: Runtime 3ms Memory 17.10MB
Link: https://leetcode.com/problems/largest-number/
*/
static bool cmp(const string &a, const string &b)
{
        return a + b > b + a;
}
class Solution
{
public:

    string largestNumber(vector<int> &nums)
    {
        vector<string> numStrs;
        for (int num : nums)
            numStrs.push_back(to_string(num));

        sort(numStrs.begin(), numStrs.end(), cmp);

        if (numStrs[0] == "0")
            return "0";

        string result;
        for (const string &s : numStrs)
            result += s;

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums) << endl;
    return 0;
}