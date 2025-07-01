#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
LeetCode 12. Roman to Integer

Time Complexity: O(N), where N is the length of the input string.
- Each character in the string is processed once.

Space Complexity: O(1), as only a constant amount of extra space is used.

Approach:
- Iterate through the Roman numeral string.
- For each character, check if it forms a subtractive pair with the next character.
- If so, subtract its value; otherwise, add its value.
- Accumulate the result and return the final integer.

Result: Runtime: 0 ms, Memory Usage: 10.14 MB
Link: https://leetcode.com/problems/roman-to-integer/
*/

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size()) {
            if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) {
                result -= 1;
                continue;
            }
            if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) {
                result -= 10;
                continue;
            }
            if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) {
                result -= 100;
                continue;
            }
            }
            switch (s[i]) {
            case 'I': result += 1; break;
            case 'V': result += 5; break;
            case 'X': result += 10; break;
            case 'L': result += 50; break;
            case 'C': result += 100; break;
            case 'D': result += 500; break;
            case 'M': result += 1000; break;
            default: break;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string roman = "XXVII";
    cout << sol.romanToInt(roman) << endl;
    return 0;
}