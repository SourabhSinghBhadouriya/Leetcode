#include<bits/stdc++.h>
using namespace std;

// 1034. Coloring A Border

void dfs(vector<vector<int>>& grid, int i, int j, int clr){
        grid[i][j] = -clr;
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        for(vector<int> &d : dir){
            int r = i + d[0];
            int c = j + d[1];
            if(r >= 0 && c >= 0 && r < n && c < m && abs(grid[r][c]) == clr){
                count ++;
                 if(grid[r][c] == clr){
                     dfs(grid,r,c,clr);
                 }
            }
        }
        if(count == 4){
            grid[i][j] = clr;
        }
    }
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        dfs(grid,row,col,grid[row][col]);
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] < 0){
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }


// 1020. Number of Enclaves

void dfs(vector<vector<int>>& grid,int i,int j){
        grid[i][j] = 0;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        for(vector<int> &d : dir){
            int r = i + d[0];
            int c = j + d[1];

            if( r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1){
                dfs(grid,r,c);
            }
        }
    }
int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        dfs(grid,i,j);
                    }
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }

// Number of Distinct Islands
// Method 1

void dfs(int row,int col,vector<vector<int>>& grid, vector<vector<bool>> &vis,vector<pair<int,int>> &vec,int row0,int col0){
      int n = grid.size(),m = grid[0].size();
      vis[row][col] = true;
      vec.push_back({row-row0,col-col0});
      vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
      for(vector<int> &d : dir){
          int r = row + d[0];
          int c = col + d[1];
          
          if(r >=0 && c >= 0 && r < n && c < m && !vis[r][c] && grid[r][c]){
              dfs(r,c,grid,vis,vec,row0,col0);
          }
      }
  }
  
int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }

 // Method 2

string psf;
void dfs(vector<vector<int>>& grid,int row,int col){
        grid[row][col] = 0;
        if(row-1 >= 0 && grid[row-1][col] == 1){
            psf += "t";
            dfs(grid,row-1,col);
        }
        if(col-1 >= 0 && grid[row][col-1] == 1){
            psf += "l";
            dfs(grid,row,col-1);
        }
        if(row+1 < grid.size() && grid[row+1][col] == 1){
            psf += "d";
            dfs(grid,row+1,col);
        }
        if(col+1 < grid[0].size() && grid[row][col+1] == 1){
            psf += "r";
            dfs(grid,row,col+1);
        }
        psf += "b";
    }
int countDistinctIslands(vector<vector<int>>& grid) {
        set<string> set;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                   psf = "";
                   psf += "x";
                   dfs(grid,i,j);
                   set.insert(psf);
                }
            }
        }
        return set.size();
    }