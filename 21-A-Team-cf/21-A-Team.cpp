#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: A. Team (Codeforces 231A)

Time Complexity: O(n)
- n is the number of problems.
- For each problem, we check the three team members' opinions in O(1) time.

Space Complexity: O(1)
- Only a counter is used to track the number of problems the team will solve.

Approach:
- For each problem, read the opinions of three team members (1 if sure, 0 if not).
- If at least two members are sure about the solution, increment the counter.
- Output the total number of problems the team will solve.

Link: https://codeforces.com/problemset/problem/231/A
*/

int QuestionsSolvedByTeam(vector<vector<int>>& team)
{
    int cnt = 0;
    for(vector<int> i: team)
    {
        int cond = 0;
        for (int j: i)
        {
            cond+=j;
        }
        if(cond >= 2)
        {
            cnt++;
        }
    }

    return cnt;
}


int main()
{
    vector<vector<int>> problemSet;
    int cnt = 0;

    cin >> cnt;
    for(int i = 0; i < cnt; i++)
    {
        int a; int b; int c;
        cin >> a;
        cin >> b;
        cin >> c;

        problemSet.push_back({a,b,c});
    }

    cout << QuestionsSolvedByTeam(problemSet) << endl;

}