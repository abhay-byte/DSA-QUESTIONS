#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

static bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numStrs;
        numStrs.reserve(nums.size());
        for (int num : nums)
            numStrs.push_back(to_string(num));

        sort(numStrs.begin(), numStrs.end(), cmp);

        if (numStrs[0] == "0")
            return "0";

        size_t totalLen = 0;
        for (const string &s : numStrs)
            totalLen += s.size();

        string result;
        result.reserve(totalLen);
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
