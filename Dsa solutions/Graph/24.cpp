#include<bits/stdc++.h>
using namespace std;

// 305 Number of Island 2

vector<int> numIslands2(int n, int m, vector<vector<int>> &positions)
{
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n * m; i++)
        par.push_back(i);

    vector<int> ans;
    int count = 0;
    for (vector<int> &pos : positions)
    {
        int i = pos[0], j = pos[1];
        if (grid[i][j] == 1)
        {
            ans.push_back(count);
            continue;
        }

        grid[i][j] = 1;
        count++;
        int p1 = findPar(i * m + j);
        for (vector<int> &d : dir)
        {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)
            {
                int p2 = findPar(r * m + c);
                if (p1 != p2)
                {
                    count--;
                    par[p2] = p1;
                }
            }
        }

        ans.push_back(count);
    }
    return ans;
}

// without using grid
vector<int> numIslands2(int n, int m, vector<vector<int>> &positions)
{
    par.resize(n * m, -1);
    vector<int> ans;
    int count = 0;
    for (vector<int> &pos : positions)
    {
        int i = pos[0], j = pos[1];
        if (par[i * m + j] != -1)
        {
            ans.push_back(count);
            continue;
        }

        par[i * m + j] = (i * m + j);
        count++;

        for (vector<int> &d : dir)
        {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 && r < n && c >= 0 && c < m && par[r * m + c] != -1)
            {
                int p1 = findPar(i * m + j);
                int p2 = findPar(r * m + c);
                if (p1 != p2)
                {
                    count--;
                    par[p1] = p2;
                }
            }
        }

        ans.push_back(count);
    }
    return ans;
}
