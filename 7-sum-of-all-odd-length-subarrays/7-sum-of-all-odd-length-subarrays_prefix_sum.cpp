#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Time Complexity: O(N^2), where N is the length of the input array.
- The outer loop runs N times.
- For each starting index, the inner loop considers all odd lengths up to N.
- Prefix sums allow each subarray sum to be computed in O(1) time.

Space Complexity: O(N), due to the prefix sum array used for each iteration.

Approach:
- For each starting index, build a prefix sum array.
- For all possible odd subarray lengths starting at that index, use the prefix sum to compute the subarray sum efficiently.
- Accumulate the result.

Result: Runtime: 4 ms, Memory Usage: 13.46 MB
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
            // Compute prefix sum
            vector<int> prefix(n + 1, 0);
            for (int k = 0; k < n; ++k)
                prefix[k + 1] = prefix[k] + arr[k];

            for (int len = 1; i + len <= n; len += 2)
            {
                // sum of subarray arr[i..i+len-1] using prefix sum
                sum += prefix[i + len] - prefix[i];
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