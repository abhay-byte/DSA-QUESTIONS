#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
LeetCode 20. Valid Parentheses

Time Complexity: O(N), where N is the length of the input string.
- Each character is processed once.

Space Complexity: O(N), for the stack used to store opening brackets.

Approach:
- Use a stack to track opening brackets.
- For each closing bracket, check if it matches the top of the stack.
- If all brackets are matched correctly, the string is valid.

Link: https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else {
                if (stack.empty()) return false;
                char top = stack.back();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};