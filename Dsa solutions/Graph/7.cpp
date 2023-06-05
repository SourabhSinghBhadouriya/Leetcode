
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