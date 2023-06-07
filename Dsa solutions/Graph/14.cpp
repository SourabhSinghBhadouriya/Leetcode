#include<bits/stdc++.h>
using namespace std;

// 1091. Shortest Path in Binary Matrix

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size(), shortestPath = 1;
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        queue<int> que;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 } };

        que.push(0);
        while (!que.empty()) {
            int size = que.size();
            while (size-- ) {
                int idx = que.front();
                que.pop();
                int sr = idx / m, sc = idx % m;
                if (sr == n - 1 && sc == m - 1)
                    return shortestPath;
                for (vector<int> &d : dir) {
                    int r = sr + d[0];
                    int c = sc + d[1];

                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 0) {
                        grid[r][c] = 1;
                        que.push(r * m + c);
                    }
                }
            }

            shortestPath++;
        }

        return -1;
    }
