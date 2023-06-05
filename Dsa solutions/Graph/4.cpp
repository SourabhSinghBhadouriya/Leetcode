
// 1971 Find if Path Exists in Graph

bool dfs(vector<vector<int>>& adj,vector<int> &vis, int src, int dest){
        if (src == dest)
            return true;

        bool res = false;
        vis[src] = true;
        for (auto i : adj[src]) {
            if (!vis[i])
                res = res || dfs(adj,vis,i, dest);
        }

        return res;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //creating adjacency list
        vector<vector<int>>adj(n);
	    for(auto i : edges){
	        adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
	    }
        // visited vector
	    vector<int> visited(n,0);
        //dfs traversal
        return dfs(adj,visited,source,destination);
    }