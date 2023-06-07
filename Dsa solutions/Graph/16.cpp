#include<bits/stdc++.h>
using namespace std;

// 1020. Number of Enclaves

int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size(),ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        queue<int> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if (grid[i][j] == 1){
                        que.push(i * m + j);
                        vis[i][j] = true;
                    }
                }
            }
    }
     while (!que.empty()) {
            int size = que.size();
            while (size-- ) {
                int idx = que.front();
                que.pop();
                int sr = idx / m, sc = idx % m;

                for (vector<int> &d : dir) {
                    int r = sr + d[0];
                    int c = sc + d[1];

                    if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && grid[r][c]) {
                        vis[r][c] = true;
                        que.push(r * m + c);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j])
                ans++;
            }
        }
        return ans;
    }