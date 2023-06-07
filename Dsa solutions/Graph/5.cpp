#include<bits/stdc++.h>
using namespace std;

// 797. All Paths From Source to Target

void dfs(vector<vector<int>>& graph,int src,int dest,vector<int> path,vector<vector<int>> &paths){
        // insert the src
        path.push_back(src);
        // base case
        if(src == dest){
            paths.push_back(path);
            return;
        }
        // dfs traversal
        for(auto x : graph[src]){
            dfs(graph,x,dest,path,paths);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        int nodes = graph.size();
        dfs(graph,0,nodes-1,path,paths);
        return paths;
    }