#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
Problem: 22-Next-Round (Codeforces 158A)

Time Complexity: O(n)
- n is the number of participants.
- For each participant, we check their score in O(1) time.

Space Complexity: O(n)
- A vector is used to store the scores of all participants.

Approach:
- Read the number of participants and the k-th position.
- Read the scores of all participants.
- Count how many participants have a score greater than or equal to the k-th participant's score and are greater than zero.
- Output the total number of such participants.

Link: https://codeforces.com/problemset/problem/158/A
*/

// Returns the number of participants who advance to the next round
int countAdvancingParticipants(const vector<int>& scores, int k)
{
    int totalParticipants = scores.size();
    if (k < 1 || k > totalParticipants) return 0;

    int kthScore = scores[k - 1];
    int advancingCount = 0;

    for (int score : scores)
    {
        if (score >= kthScore && score > 0)
        {
            ++advancingCount;
        }
    }
    return advancingCount;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> scores(n);
    for (int& score : scores)
    {
        cin >> score;
    }

    cout << countAdvancingParticipants(scores, k) << endl;
    return 0;
}

