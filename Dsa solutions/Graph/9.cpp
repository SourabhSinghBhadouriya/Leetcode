//130. Surrounded Regions

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
