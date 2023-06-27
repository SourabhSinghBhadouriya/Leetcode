#include <bits/stdc++.h>
using namespace std;


// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n+1), dsuBob(n+1);
        int redundantEdges = 0, aliceEdges = 0, bobEdges = 0;

        for (auto e : edges) {
            if (e[0] == 3) {
                int n1 = e[1], n2 = e[2];
                if ((dsuAlice.findParent(n1) != dsuAlice.findParent(n2)) && (dsuBob.findParent(n1) != dsuBob.findParent(n2))) {
                    dsuAlice.makeUnion(n1, n2);
                    dsuBob.makeUnion(n1, n2);
                    aliceEdges++;
                    bobEdges++;
                }
                else {
                    redundantEdges++;
                }
            }
        }

        for (auto e : edges) {
            int n1 = e[1], n2 = e[2];
            if (e[0] == 1) {
                if (dsuAlice.findParent(n1) != dsuAlice.findParent(n2)) {
                    dsuAlice.makeUnion(n1, n2);
                    aliceEdges++;
                }
                else {
                    redundantEdges++;
                }
            }
            else if (e[0] == 2) {
                if (dsuBob.findParent(n1) != dsuBob.findParent(n2)) {
                    dsuBob.makeUnion(n1, n2);
                    bobEdges++;
                }
                else {
                    redundantEdges++;
                }
            }
        }
        return (aliceEdges == n-1 && bobEdges == n-1) ? redundantEdges : -1;
    }
};

// 1061. Lexicographically Smallest Equivalent String

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = i;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] < rank[p2]) {
                parent[p2] = p1;
            }
            else {
                parent[p1] = p2;
            }
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        for(int i=0;i<s1.size();i++){
            dsu.makeUnion(s1[i]-'a',s2[i]-'a');
        }
    string ans = "";
    for (char ch : baseStr)
    {
        int p = dsu.findParent(ch - 'a'); // char ch = dsu.findParent(ch - 'a') + 'a';
        ans += (char)(p + 'a');   // ans += ch ;
    }

    return ans;
    }
};

// 684. Redundant Connection

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for (vector<int> &e : edges){
        int u = e[0], v = e[1];
        if(dsu.findParent(u) == dsu.findParent(v)){
            return e;
        }
        dsu.makeUnion(u,v);
        }
        return {};
    }
};

// 2492. Minimum Score of a Path Between Two Cities

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(auto &r : roads){
            int node1 = r[0],node2 = r[1];
            dsu.makeUnion(node1,node2);
        }

        int ans = INT_MAX;
        int x = dsu.findParent(1);
        for(auto &r : roads){
            int node1 = r[0],node2 = r[1],dist = r[2];
            int par1 = dsu.findParent(node1);
            if(par1 == x){
                ans = min(ans,dist);
            }
        }
        return ans;
    }
};


// 839. Similar String Groups

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
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
        DSU dsu(n);
        int noOfSet = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    if (dsu.findParent(i) != dsu.findParent(j)) {
                        noOfSet--;
                        dsu.makeUnion(i,j);
                    }
                }
            }
        }
        return noOfSet;
    }
};

// 1319. Number of Operations to Make Network Connected

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        DSU dsu(n);
        for(auto &c : connections){
            dsu.makeUnion(c[0],c[1]);
        }
        set<int> par;
        for(int i=0;i<n;i++){
            par.insert(dsu.findParent(i));
        }
        return par.size()-1;
    }
};

// 305 Number of Island 2

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
     vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        DSU dsu(n*m);
        vector<int> ans;
        for(auto &it:operators){
            int i = it[0];
            int j = it[1];
            
            if(vis[i][j] == 1){
                ans.push_back(count);
                continue;
            }
            else{
                vis[i][j]=1;
                count ++;
                vector<vector<int>> dir {{-1,0},{1,0},{0,-1},{0,1}};
                for (vector<int> &d : dir){
                    int r = i + d[0];
                    int c = j + d[1];
                    
                    if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 1){
                        if(dsu.findParent(i * m + j) != dsu.findParent(r * m + c)){
                            dsu.makeUnion(i * m + j,r * m + c);
                            count--;
                        }
                    }
                }
            ans.push_back(count);
            }
        }
        return ans;
    }
};

// 547. Number of Provinces

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    dsu.makeUnion(i,j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dsu.findParent(i) == i)count++;
        }
        return count;
    }
};

// 1168 - Optimize Water Distribution in a Village

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    DSU dsu(n+1);
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    int cost = 0;
    for (vector<int> &e : pipes)
    {
        int u = e[0], v = e[1], w = e[2];
        if(dsu.findParent(u) != dsu.findParent(v)){
            dsu.makeUnion(u,v);
            cost += w;
        }
    }
    return cost;
}

// 1584. Min Cost to Connect All Points

class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};
class Solution {
private : 
int distance(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<vector<int>> list;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                list.push_back({ i, j ,distance(points, i, j)});
            }
        }

        sort(list.begin(),list.end(), [](vector<int> &a, vector<int> &b){
             return a[2] < b[2]; });

        int cost = 0;
        for (vector<int> &e : list) {
            int u = e[0], v = e[1], w = e[2];

            if (dsu.findParent(u) != dsu.findParent(v)) {
                dsu.makeUnion(u,v);
                cost += w;
            }
        }
        return cost;
    }
};
// 924. Minimize Malware Spread

class DSU {
public:
    vector<int>rank;
    vector<int>parent;

    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 0 || i == j)
                    continue;

                if (dsu.findParent(i) != dsu.findParent(j)) {
                    dsu.makeUnion(i,j);
                }
            }
        }

        vector<int> infectedCount (n,0);
        for (int &ele : initial) {
            int p = dsu.findParent(ele);
            infectedCount[p]++;
        }

        sort(initial.begin(),initial.end());

        int ans = initial[0];
        int maxPopulation = 0;
        for (int &ele : initial) {
            int p = dsu.findParent(ele);
            if (infectedCount[p] == 1 && dsu.rank[p] > maxPopulation) {
                maxPopulation = dsu.rank[p];
                ans = ele;
            }
        }

        return ans;
    }
};