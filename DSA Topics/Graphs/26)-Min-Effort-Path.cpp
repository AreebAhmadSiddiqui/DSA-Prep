#include<bits/stdc++.h>
using namespace std;
class Prg
{
    public:
    int minEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // min heap

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                {
                    int maxDiff = max(diff, abs(heights[newRow][newCol] - heights[row][col]));

                    if (maxDiff < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = maxDiff;
                        pq.push({maxDiff, {newRow, newCol}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};