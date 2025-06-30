#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            vector<int> subarrays;
            for(int j = i; j < arr.size(); j++)
            {  
                subarrays.push_back(arr[j]);
            }
            if (subarrays.size()%2 != 0)
            {
                for(int k: subarrays)
                {
                    sum+=k;
                }
            }
            
        }
        return sum;
    }
};

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    Solution sol;
    int result = sol.sumOddLengthSubarrays(arr);
    cout << result << endl;
    return 0;
}