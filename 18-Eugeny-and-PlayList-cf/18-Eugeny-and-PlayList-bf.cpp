#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
Problem: Eugeny and Playlist (Codeforces 302A)

Time Complexity: O(n * m)
- For each of the m moments, we may iterate through up to n songs.

Space Complexity: O(n + m)
- We store the song list and the moments.

Approach:
- For each moment, iterate through the playlist, summing up the total time.
- When the cumulative time reaches or exceeds the moment, output the current song index.

Link: https://codeforces.com/problemset/problem/302/A
*/


void FindSongPlayedOnMoment(vector<vector<int>> pair, vector<int> moments)
{

    vector<int> songsPlayedAtMoment;

    for(int i: moments)
    {
        int val = 0;

        for(int j = 0; j < pair.size(); j++)
        {
            val += pair[j][0]*pair[j][1];
            if (val >= i)
            {
                songsPlayedAtMoment.push_back(j+1);
                break;
            }
        }
    }

    for (int i : songsPlayedAtMoment)
    {
        cout << i << endl;
    }  
}

int main()
{
    int n; int m;
    vector<vector<int>> pair;
    vector<int> moments;

    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)
    {
        int c;
        int t;
        cin >> c;
        cin >> t;
        vector<int> temp = {c,t};
        pair.push_back(temp);
    }

    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        moments.push_back(temp);
    }
    FindSongPlayedOnMoment(pair,moments);
}