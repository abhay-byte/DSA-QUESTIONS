#include <iostream>
#include <vector>
using namespace std;


/*
Time Complexity: O(log(n))
Space Complexity: O(1)

Approach:
The function iterates through each digit of the integer n by repeatedly taking the modulus and division by 10.
It calculates the sum and product of the digits, then returns the difference between the product and the sum.

Result: Runtime: 0 ms Memory Usage: 7.7 MB
Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0; int product = 1;

        while(n!=0)
        {
            int digit = n%10;
            sum += digit;
            product = product*digit;

            int temp = n/10;
            n = temp;
        }

        return product - sum;
    }
};