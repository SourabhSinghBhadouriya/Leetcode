#include<bits/stdc++.h>
using namespace std;

// 994. Rotting Oranges

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    queue<int> que;

    int time = 0, orangeCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                que.push(i * m + j);
            else if (grid[i][j] == 1)
                orangeCount++;
        }
    }

    if (orangeCount == 0)
        return 0;

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!que.empty())
    {
        int size = que.size();
        while (size-- )
        {
            int idx = que.front();
            que.pop();

            int sr = idx / m, sc = idx % m;

            for (vector<int> &d : dir)
            {
                int r = sr + d[0];
                int c = sc + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    que.push(r * m + c);
                    orangeCount--;
                    if (orangeCount == 0)
                        return time + 1;
                }
            }
        }
        time++;
    }

    return -1;
}

// 1091. Shortest Path in Binary Matrix

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size(), shortestPath = 1;
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        queue<int> que;
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 } };

        que.push(0);
        while (!que.empty()) {
            int size = que.size();
            while (size-- ) {
                int idx = que.front();
                que.pop();
                int sr = idx / m, sc = idx % m;
                if (sr == n - 1 && sc == m - 1)
                    return shortestPath;
                for (vector<int> &d : dir) {
                    int r = sr + d[0];
                    int c = sc + d[1];

                    if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 0) {
                        grid[r][c] = 1;
                        que.push(r * m + c);
                    }
                }
            }

            shortestPath++;
        }

        return -1;
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

// 1020. Number of Enclaves

int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size(),ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        queue<int> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if (grid[i][j] == 1){
                        que.push(i * m + j);
                        vis[i][j] = true;
                    }
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

                    if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && grid[r][c]) {
                        vis[r][c] = true;
                        que.push(r * m + c);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j])
                ans++;
            }
        }
        return ans;
    }

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

// 785. Is Graph Bipartite?
  
bool bipartite(vector<vector<int>>& graph, int src, vector<int> &vis) {
        queue<int> que;
        que.push(src);

        // No Color : -1 , Red : 0, Green : 1
        int color = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size-- ) {
                int rvtx = que.front();
                que.pop();
                if (vis[rvtx] != -1) {
                    if (color != vis[rvtx]) // conflict
                        return false;
                    continue;
                }

                vis[rvtx] = color;
                for (int v : graph[rvtx]) {
                    if (vis[v] == -1) {
                        que.push(v);
                    }
                }
            }

            color = (color + 1) % 2;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1 && !bipartite(graph, i, vis))
                return false;
        }

        return true;
    }

// 207 Course Schedule

bool canFinish(int N, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);

    for (vector<int> &ar : prerequisites)
    {
        graph[ar[0]].push_back(ar[1]);
        indegree[ar[1]]++;
    }

    queue<int> que;
    for (int i = 0; i < N; i++){
        if (indegree[i] == 0)
            que.push(i);
    }

    int vtxCount = 0;
    while (!que.empty())
    {
        int vtx = que.front();
        que.pop();
        vtxCount++;
        for (int v : graph[vtx])
        {
            if (--indegree[v] == 0)
                que.push(v);
        }
    }

    return vtxCount == N;
}

// 210 Course Schedule II

vector<int> findOrder(int N, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);

    for (vector<int> &ar : prerequisites)
    {
        graph[ar[1]].push_back(ar[0]);
        indegree[ar[0]]++;
    }

    queue<int> que;
    for (int i = 0; i < N; i++)
        if (indegree[i] == 0)
            que.push(i);

    vector<int> ans;
    while (que.size() != 0)
    {
        int vtx = que.front();
        que.pop();
        ans.push_back(vtx);
        for (int v : graph[vtx])
        {
            if (--indegree[v] == 0)
                que.push(v);
        }
    }

    if (ans.size() != N)
        ans.clear();

    return ans;
}

// 210 Course Schedule II
vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(N);
        vector<int> indegree(N,0);
        for(vector<int> &ar : prerequisites){
            graph[ar[0]].push_back(ar[1]);
            indegree[ar[1]]++;
        }
        queue<int> que;
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(indegree[i] == 0)
               que.push(i);
        }
        while(!que.empty()){
            int vtx = que.front();
            que.pop();
            ans.push_back(vtx);
            for(int v : graph[vtx]){
                if(--indegree[v] == 0){
                    que.push(v);
                }
            }
        }
        if(ans.size() != N)ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }

// 329 Longest Increasing Path in a Matrix

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> indegree(n, vector<int>(m, 0));

    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (vector<int> &d : dir)
            {
                int r = i + d[0];
                int c = j + d[1];
                if (r >= 0 && c >= 0 && r < n && c < m && matrix[r][c] < matrix[i][j])
                {
                    indegree[i][j]++;
                }
            }

            if (indegree[i][j] == 0)
                que.push(i * m + j);
        }
    }

    int level = 0;
    while (!que.empty())
    {
        int size = que.size();
        while (size-- )
        {
            int idx = que.front();
            que.pop();
            int i = idx / m, j = idx % m;

            for (vector<int> &d : dir)
            {
                int r = i + d[0];
                int c = j + d[1];
                if (r >= 0 && c >= 0 && r < n && c < m && matrix[r][c] > matrix[i][j] && --indegree[r][c] == 0)
                    que.push(r * m + c);
            }
        }
        level++;
    }

    return level;
}

