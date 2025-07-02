#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
Problem: Eugeny and Playlist (Codeforces 302A)

Time Complexity: O(n + m log n)
- Building the prefix sum array for song end times takes O(n).
- For each of the m queries, binary search is used, taking O(log n) per query.

Space Complexity: O(n + m)
- Stores prefix sums for n songs and m query moments.

Approach:
- For each song, calculate its total duration and build a prefix sum array representing the end time of each song.
- For each query moment, use binary search to find which song is playing at that moment.

Link: https://codeforces.com/problemset/problem/302/A
*/

void FindSongPlayedOnMoment(vector<vector<int>> pair, vector<int> moments)
{
    vector<int> songsPlayedAtMoment;
    vector<int> playlistTimeline;

        // Build prefix sums for song end times if not already built
    if (playlistTimeline.empty()) {
        int sum = 0;
        for (auto &p : pair) {
            sum += p[0] * p[1];
            playlistTimeline.push_back(sum);
        }
    }

    for(int i: moments)
    {
        // Binary search to find the song being played at moment i
        int left = 0, right = playlistTimeline.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (i <= playlistTimeline[mid]) {
            ans = mid;
            right = mid - 1;
            } else {
            left = mid + 1;
            }
        }
        songsPlayedAtMoment.push_back(ans + 1); // 1-based indexing
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