#include<bits/stdc++.h>
using namespace std;

// 1254. Number of Closed Islands

void dfs(vector<vector<int>>& grid,int i,int j){
        int n = grid.size(),m = grid[0].size();
        grid[i][j] = 1;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        for(vector<int> &d : dir){
          int r = i + d[0];
          int c = j + d[1];
          
          if(r >=0 && c >= 0 && r < n && c < m  && grid[r][c] == 0)
              dfs(grid,r,c);
          }
    }
int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        // boundary dfs
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0 && i == n-1 && j == m-1){
                    if(grid[i][j] == 0){
                        dfs(grid,i,j);
                    }
                }
            }
        }
        int ans=0;
        // dfs for whole grid
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }