#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Time Complexity: O(N^3), where N is the length of the input array.
- The outer loop runs N times.
- The middle loop runs up to N times for each i, but only for odd lengths.
- The inner loop sums up to N elements for each subarray.

Space Complexity: O(1), as only a constant amount of extra space is used.

Approach:
- Iterate over all possible starting indices.
- For each starting index, consider all odd-length subarrays.
- Sum the elements of each odd-length subarray and add to the total sum.

Result: Result: Runtime: 0 ms, Memory Usage: 11.1 MB
*/
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int len = 1; i + len <= n; len += 2)
            {
                for (int j = i; j < i + len; j++)
                {
                    sum += arr[j];
                }
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    Solution sol;
    int result = sol.sumOddLengthSubarrays(arr);
    cout << result << endl;
    return 0;
}