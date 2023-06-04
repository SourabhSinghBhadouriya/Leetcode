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