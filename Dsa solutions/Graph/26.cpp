//733 Flood Fill

 void dfs(vector<vector<int>>& image, int i, int j,int val, int color){
        image[i][j] = color;
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int n = image.size(),m=image[0].size();
        for (vector<int> &d : dir)
                   {
                        int r = i + d[0];
                        int c = j + d[1];
                        if(r >= 0 && c >= 0 && r < n && c < m && image[r][c] == val)
                            dfs(image,r,c,val,color);
                    }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        if(val == color)return image;
        dfs(image,sr,sc,val,color);
        return image;
    }