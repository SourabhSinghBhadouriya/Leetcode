//329 Longest Increasing Path in a Matrix

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