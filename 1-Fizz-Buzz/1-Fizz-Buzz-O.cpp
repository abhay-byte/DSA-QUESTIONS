#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(1)

Approach: 
We iterate from 1 to n.
For each number in this range, we check if it is divisible by 3, 5, or both.
If divisible by both 3 and 5, we add "FizzBuzz" to the result.
If divisible only by 3, we add "Fizz".
If divisible only by 5, we add "Buzz".
Otherwise, we add the number itself as a string.
Finally, we return the result vector.

Result: Runtime: 0 ms Memory Usage: 11.8 MB   
Link: https://leetcode.com/problems/fizz-buzz/
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <=n ; i++)
        {
            if(i%3==0 && i%5==0)
            {
                result.push_back("FizzBuzz");
            }
            else if (i%3==0)
            {
                result.push_back("Fizz");
            }
            else if (i%5==0)
            {
                result.push_back("Buzz");
            }
            else
            {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};

int main()
{

}