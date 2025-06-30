#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(N + B), where N is the length of the text and B is the length of brokenLetters.
Space Complexity: O(1) (since the broken array size is constant 26).

Approach:
- Mark all broken letters in a boolean array.
- Iterate through each word in the text.
- For each word, check if it contains any broken letter.
- If not, increment the count.
- Return the total count of words that can be typed.

Result: Runtime: 0 ms, Memory Usage: 8.7 MB
Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
*/
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }
        int count = 0;
        int n = text.size();
        int i = 0;
        while (i < n) {
            bool canType = true;
            while (i < n && text[i] != ' ') {
                if (broken[text[i] - 'a']) {
                    canType = false;
                }
                i++;
            }
            if (canType) count++;
            while (i < n && text[i] == ' ') i++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string text = "leet code";
    string brokenLetters = "lt";
    int result = sol.canBeTypedWords(text, brokenLetters);
    cout << result << endl;
    return 0;
}