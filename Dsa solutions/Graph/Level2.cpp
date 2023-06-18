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

// 542. 01 Matrix

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        queue<int> que;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    que.push(i * m + j);
                    vis[i][j] = true;
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

                    if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c]) {
                        grid[r][c] = grid[sr][sc] + 1;
                        vis[r][c] = true;
                        que.push(r * m + c);
                    }

                }
            }
        }

        return grid;
    }

// 542. 01 Matrix(without visited vector of vector)

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        queue<int> que;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    que.push(i * m + j);
                }
                else{
                    grid[i][j] = -1;
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

                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] < 0) {
                        grid[r][c] = grid[sr][sc] + 1;
                        que.push(r * m + c);
                    }
                }
            }
        }

        return grid;
    }

//  994. Rotting Oranges

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size(),fresh=0;
        queue<int> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                   que.push(i*m+j);
                else if(grid[i][j] == 1)
                   fresh++;
            }
        }
        if(fresh == 0)return 0;
        int level = -1;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        while(!que.empty()){
            level++;
            int size = que.size();
            while(size--){
                int idx = que.front();
                que.pop();
                int sr = idx / m,sc = idx % m;
                for(vector<int> &d : dir){
                    int r = sr + d[0];
                    int c = sc + d[1];

                    if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1){
                        grid[r][c] = 2;
                        que.push(r*m+c);
                        fresh--;
                    }
                }
            }
        }
        if(fresh == 0){
            return level;
        }
        else{
            return -1;
        }
    }

// 1162. As Far from Land as Possible

int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<int> que;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    que.push(i * m + j);
                }
            }
        }

        if(que.size() == 0 || que.size() == n * m)return -1;
        int level = -1;
        while (!que.empty()) {
            level++;
            int size = que.size();
            while (size-- ) {
                int idx = que.front();
                que.pop();
                int sr = idx / m, sc = idx % m;

                for (vector<int> &d : dir) {
                    int r = sr + d[0];
                    int c = sc + d[1];

                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 0) {
                        grid[r][c] = 1;
                        que.push(r * m + c);
                    }
                }
            }
        }
        return level;
    }

// 934. Shortest Bridge

void dfs(int i,int j,vector<vector<int>>& grid,queue<int> &que,vector<vector<bool>> &vis){
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        vis[i][j] = true;
        que.push(i * m + j);
        for(vector<int> & d : dir){
            int r = i + d[0];
            int c = j + d[1];

            if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1 && !vis[r][c]){
                dfs(r,c,grid,que,vis);
            }
        }
    }
int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<int> que;
        bool flag = false;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m && !flag;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid,que,vis);
                    flag = true;
                }
            }
        }
    int level = -1;
    vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        while(!que.empty()){
            level++;
            int size = que.size();
            while(size -- ){
                int idx = que.front();
                que.pop();
                int sr = idx / m, sc = idx % m;

                for (vector<int> &d : dir) {
                    int r = sr + d[0];
                    int c = sc + d[1];

                    if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c]  ) {
                        if(grid[r][c] == 1)return level;
                        vis[r][c] = true;
                        que.push(r * m + c);
                    }
                }
            }
        }
        return -1;
    }





