// 286 Walls and Gates
void wallsAndGates(vector<vector<int>>& grid){
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    queue<int> que;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 0){
                que.push(i*m+j);
            }
        }
    }

    while(!que.empty()){
        int size = que.size();
        while(size--){
            int idx = que.front();
            que.pop();
            int sr = idx / m, sc = idx % m;
            for (vector<int> &d : dir) {
                int r = sr + d[0];
                int c = sc + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m  && grid[r][c] == 2147483647) {
                    grid[r][c] = grid[sr][sc] + 1;
                    que.push(r * m + c);
                    }
                }
        }
    }
}

// using visited vector
void wallsAndGates(vector<vector<int>>& grid){
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<int> que;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 0){
                que.push(i*m+j);
                vis[i][j] = true;
            }
        }
    }

    while(!que.empty()){
        int size = que.size();
        while(size--){
            int idx = que.front();
            que.pop();
            int sr = idx / m, sc = idx % m;
            for (vector<int> &d : dir) {
                int r = sr + d[0];
                int c = sc + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && grid[r][c] != -1) {
                    grid[r][c] = grid[sr][sc] + 1;
                    vis[r][c] = true;
                    que.push(r * m + c);
                    }
                }
        }
    }
}
