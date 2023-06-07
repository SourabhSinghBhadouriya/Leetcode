#include<bits/stdc++.h>
using namespace std;

// 200. Number of Islands

    void dfs(vector<vector<char>>& grid,int i,int j){
        int n = grid.size(),m = grid[0].size();
        grid[i][j] = '0';
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}} ;
        for(vector<int> &d : dir){
            int r = i + d[0];
            int c = j + d[1];
            if(r >= 0 && c >= 0 && r< n && c <m && grid[r][c] == '1'){
                dfs(grid,r,c);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int components = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    components++;
                    dfs(grid,i,j);
                }
            }
        }
        return components;
    }