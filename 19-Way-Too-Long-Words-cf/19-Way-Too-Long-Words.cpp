#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: Way Too Long Words (Codeforces 71A)

Time Complexity: O(n * m)
- n is the number of words.
- m is the average length of each word.
- Each word is processed in O(1) time for abbreviation.

Space Complexity: O(n * m)
- Stores all input words in a vector.

Approach:
- For each word, if its length is greater than 10, abbreviate it by keeping the first and last character and replacing the middle with the count of omitted characters.
- Otherwise, print the word as is.

Link: https://codeforces.com/problemset/problem/71A
*/


void PrintAbv(vector<string> str)
{
    for(string s: str)
    {
        if(s.size() > 10)
        {
            cout << s[0] << s.size()-2 << s[s.size()-1] << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
}

int main()
{
    vector<string> strList;
    int count = 0;
    cin >> count;

    for(int i=0; i < count; i++)
    {
        string str;
        cin >> str;
        strList.push_back(str);
    }

    PrintAbv(strList);
    
}