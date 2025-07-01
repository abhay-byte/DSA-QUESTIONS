#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Optimized Approach:

Time Complexity: O(N), where N is the length of the input array.
- For each element, calculate its contribution to all odd-length subarrays in constant time.

Space Complexity: O(1), as only a constant amount of extra space is used.

Explanation:
- For each element at index i, count the number of odd-length subarrays it appears in.
- The total number of subarrays including arr[i] is (i + 1) * (n - i).
- Half of these (rounded up) are odd-length subarrays.
- Multiply arr[i] by this count and sum for all elements.

Result: Runtime: 0 ms, Memory Usage: 10.98 MB
*/
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int left = i + 1;
            int right = n - i;
            int total = left * right;
            int odd_count = (total + 1) / 2;
            sum += arr[i] * odd_count;
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