#include<bits/stdc++.h>
using namespace std;

//463. Island Perimeter

int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int n = grid.size(),m=grid[0].size(),onceCount =0,nbrCount =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    onceCount++;
                    for (vector<int> &d : dir)
                   {
                        int r = i + d[0];
                        int c = j + d[1];
                        if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
                            nbrCount++;
                    }
                }
            }
        }
        return 4*onceCount - nbrCount;
    }