#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }

        return ans;
    }
};

int main()
{
    Solution obj = Solution();

    vector<int> a = {2, 2, 1};

    cout << obj.singleNumber(a);
}