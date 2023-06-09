#include<bits/stdc++.h>
using namespace std;

// 695 Max Area of Island

int dfs_area(vector<vector<int>>& grid,int i,int j){
        int n = grid.size(),m = grid[0].size(),size=0;
        vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
        grid[i][j] = 0;
        for(vector<int> &d : dir){
            int r = i + d[0];
            int c = j + d[1];

            if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
            size += dfs_area(grid,r,c);
        }
        return size+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size(),maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = dfs_area(grid,i,j);
                    maxArea = max(area,maxArea);
                }
            }
        }
        return maxArea;
    }


// By Dsu 

vector<int> par,size;
    int findPar(int u){
        return par[u] == u ? u : (par[u] = findPar(par[u]));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)return 0;
        int m = grid[0].size();
        int maxsize = 0;

        for(int i=0;i<n*m;i++){
            par.push_back(i);
            size.push_back(1);
        }
        vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int p1 = findPar(i * m + j);
                    for(vector<int> &d : dir){
                        int r = i + d[0];
                        int c = j  + d[1];

                        if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1){
                            int p2 = findPar(r * m + c);
                            if(p1 != p2){
                                par[p2] = p1;
                                size[p1] += size[p2];
                            }
                        }
                    }
                    maxsize = max(maxsize,size[p1]);
                }
            }
        }
            return maxsize;
    }