#include<bits/stdc++.h>
using namespace std;

// 997. Find the Town Judge

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1,0);
        vector<int> outdeg(n+1,0);
        for(auto i: trust){
            outdeg[i[0]]++;
            indeg[i[1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(indeg[i] == n-1 && outdeg[i] == 0){
                ans=i;
                break;
            }
        }
        return ans;
    }

// 1791 Find Center of Star Graph

int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        for(auto &edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int ans = 1;
        int n = degree.size();
        for(auto &p : degree){
            if(p.second == n-1)
                ans = p.first;
        }
        return ans;
    }

// 547 Number of Provinces

 void dfs(vector<vector<int>>& isConnected,vector<bool> &vis,int i){
        int n = isConnected.size();
        vis[i] = true;
        for(int j=0;j<n;j++){
            if(!vis[j] && isConnected[i][j]){
                dfs(isConnected,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),cnt=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                cnt++;
            }
        }
        return cnt;
}

// by adjacency list
 //dfs traversal
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited, adj);
            }
        }
    }

    //solve function
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        //provinces
        int province = 0;

        //total nodes
        int n = isConnected.size();

        //creating adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        //basic dfs traversal
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {   
                //number of time this will be executed is equal to number of provinces
                province++;
                dfs(i, visited, adj);
            }
        }

        // returning provinces
        return province;
    }

// 1971 Find if Path Exists in Graph

bool dfs(vector<vector<int>>& adj,vector<int> &vis, int src, int dest){
        if (src == dest)
            return true;

        bool res = false;
        vis[src] = true;
        for (auto i : adj[src]) {
            if (!vis[i])
                res = res || dfs(adj,vis,i, dest);
        }

        return res;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //creating adjacency list
        vector<vector<int>>adj(n);
	    for(auto i : edges){
	        adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
	    }
        // visited vector
	    vector<int> visited(n,0);
        //dfs traversal
        return dfs(adj,visited,source,destination);
    }

// 797. All Paths From Source to Target

void dfs(vector<vector<int>>& graph,int src,int dest,vector<int> path,vector<vector<int>> &paths){
        // insert the src
        path.push_back(src);
        // base case
        if(src == dest){
            paths.push_back(path);
            return;
        }
        // dfs traversal
        for(auto x : graph[src]){
            dfs(graph,x,dest,path,paths);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        int nodes = graph.size();
        dfs(graph,0,nodes-1,path,paths);
        return paths;
    }

// 733 Flood Fill

 void dfs(vector<vector<int>>& image, int i, int j,int val, int color){
        image[i][j] = color;
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int n = image.size(),m=image[0].size();
        for (vector<int> &d : dir)
                   {
                        int r = i + d[0];
                        int c = j + d[1];
                        if(r >= 0 && c >= 0 && r < n && c < m && image[r][c] == val)
                            dfs(image,r,c,val,color);
                    }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        if(val == color)return image;
        dfs(image,sr,sc,val,color);
        return image;
    }

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

// 463. Island Perimeter

int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int n = grid.size(),m=grid[0].size(),onceCount =0,nbrCount =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    onceCount++;
                    for (vector<int> &d : dir)
                   {
                        int r = i + d[0];
                        int c = j + d[1];
                        if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
                            nbrCount++;
                    }
                }
            }
        }
        return 4*onceCount - nbrCount;
    }

// 130. Surrounded Regions

void dfs_surrounded(vector<vector<char>>& grid,int i,int j,vector<vector<int>> &dir){
        int n=grid.size(),m=grid[0].size();
        grid[i][j] = '$';
        for (vector<int> &d : dir)
            {
                int r = i + d[0];
                int c = j + d[1];

            if(r >= 0 && c >= 0 && r < n && c < m  && grid[r][c] == 'O')
                dfs_surrounded(grid,r,c,dir);
            }
    }
    void solve(vector<vector<char>>& grid) {
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 'O')
                        dfs_surrounded(grid,i,j,dir);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'O')
                   grid[i][j] = 'X';
                else if(grid[i][j] == '$')
                   grid[i][j] = 'O';
            }
        }
    }

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

// 73 Set Matrix Zeroes

void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> rowNum(row, 0);
        vector<int> colNum(col, 0);
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0){
                    rowNum[i] = 1;
                    colNum[j] = 1;
                }
            }
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(  rowNum[i] == 1||
                    colNum[j] == 1){
                    matrix[i][j] = 0;
                 
                }
            }
        }
    }

// 1905. Count Sub Islands

bool countSubIslands_dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int n = grid1.size(),m = grid1[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        grid2[i][j] = 0;
        bool res = true;
        for (vector<int> &d : dir) {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 && c >= 0 && r < n && c < m && grid2[r][c] == 1) {
                res = countSubIslands_dfs(grid1, grid2, r, c) && res;
            }
        }

        return res && (grid1[i][j] == 1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(),m = grid1[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    count += countSubIslands_dfs(grid1, grid2, i, j) ? 1 : 0;
                }
            }
        }

        return count;
    }



