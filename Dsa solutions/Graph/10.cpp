// Number of Distinct Islands(GFG)

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