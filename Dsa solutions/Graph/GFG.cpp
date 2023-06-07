#include<bits/stdc++.h>
using namespace std;

// BFS of graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<bool> vis(V,false);
        vis[0] = true;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int node = que.front();
            que.pop();
            bfs.push_back(node);
            for(auto x : adj[node]){
                if(!vis[x]){
                    vis[x] = true;
                    que.push(x);
                }
            }
        }
        return bfs;
    }


// DFS of Graph

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans) {
        vis[node] = 1; 
        ans.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ans); 
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ans; 
        // call dfs for starting node
        dfs(start, adj, vis, ans); 
        return ans; 
    }