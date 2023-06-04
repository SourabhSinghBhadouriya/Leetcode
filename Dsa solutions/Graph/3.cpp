// 547 Number of Provinces

 void dfs(vector<vector<int>>& isConnected,vector<bool> &vis,int i){
        int n = isConnected.size();
        vis[i] = true;
        for(int j=0;j<n;j++){
            if(!vis[j] && isConnected[i][j]){
                dfs(isConnected,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),cnt=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                cnt++;
            }
        }
        return cnt;
}

// by adjacency list
 //dfs traversal
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited, adj);
            }
        }
    }

    //solve function
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        //provinces
        int province = 0;

        //total nodes
        int n = isConnected.size();

        //creating adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        //basic dfs traversal
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {   
                //number of time this will be executed is equal to number of provinces
                province++;
                dfs(i, visited, adj);
            }
        }

        // returning provinces
        return province;
    }