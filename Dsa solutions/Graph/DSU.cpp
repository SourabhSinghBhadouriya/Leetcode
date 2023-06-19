#include <bits/stdc++.h>
using namespace std;

// 695 Max Area of Island

vector<int> par,size;
    int findPar(int u){
        return par[u] == u ? u : (par[u] = findPar(par[u]));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)return 0;
        int m = grid[0].size();
        int maxsize = 0;

        for(int i=0;i<n*m;i++){
            par.push_back(i);
            size.push_back(1);
        }
        vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int p1 = findPar(i * m + j);
                    for(vector<int> &d : dir){
                        int r = i + d[0];
                        int c = j  + d[1];

                        if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1){
                            int p2 = findPar(r * m + c);
                            if(p1 != p2){
                                par[p2] = p1;
                                size[p1] += size[p2];
                            }
                        }
                    }
                    maxsize = max(maxsize,size[p1]);
                }
            }
        }
            return maxsize;
    }

// 684 Redundant Connection

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    for (int i = 0; i < n; i++)
        par.push_back(i);

    for (vector<int> &e : edges)
    {
        int u = e[0], v = e[1];
        int p1 = findPar(u), p2 = findPar(v);
        if (p1 != p2)
        {
            par[p1] = p2;
        }
        else
            return e;
    }

    return {};
}

// 1061 Lexicographically smallestEquivalentString

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}

string smallestEquivalentString(string s1, string s2, string baseStr){
    for (int i = 0; i < 26; i++)
        par.push_back(i);
    for (int i = 0; i < s1.length(); i++)
    {
        char c1 = s1[i], c2 = s2[i];
        int p1 = findPar(c1 - 'a'), p2 = findPar(c2 - 'a');
        par[p1] = min(p1, p2);
        par[p2] = min(p1, p2);
    }

    string ans = "";
    for (char ch : baseStr)
    {
        int p = findPar(ch - 'a');
        ans += (char)(p + 'a');
    }

    return ans;
   }

// 305 Number of Island 2
vector<int> par;
vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
int findPar(int u)
{
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}
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

vector<int> par;
vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
int findPar(int u)
{
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}
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

// 1168 Optimize Water Distribution in a Village

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}

int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2]; });

    for (int i = 0; i <= n; i++)
        par.push_back(i);

    int cost = 0;
    for (vector<int> &e : pipes)
    {
        int u = e[0], v = e[1], w = e[2];
        int p1 = findPar(u), p2 = findPar(v);
        if (p1 != p2)
        {
            par[p1] = p2;
            cost += w;
        }
    }

    return cost;
}

// 839. Similar String Groups

vector<int> par;
int findPar(int u){
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}
bool isSimilar(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i] && ++count > 2)
                return false;
        }
        return true;
    }

int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    par.resize(n,-1);
        for (int i = 0; i < n; i++)
            par[i] = i;

        int noOfSet = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    int p1 = findPar(i);
                    int p2 = findPar(j);

                    if (p1 != p2) {
                        par[p1] = p2;
                        noOfSet--;
                    }
                }
            }
        }
        return noOfSet;
    }