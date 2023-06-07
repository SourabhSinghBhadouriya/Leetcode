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


// 