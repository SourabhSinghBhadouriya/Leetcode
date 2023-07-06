#include<bits/stdc++.h>
using namespace std;

// 62. Unique Paths

int mazePath_tabu(int SR, int SC, int ER, int EC, vector<vector<int>> &dp, vector<vector<int>> &dir) {
        for (int sr = ER; sr >= SR; sr--) {
            for (int sc = EC; sc >= SC; sc--) {
                if (sr == ER && sc == EC) {
                    dp[sr][sc] = 1;
                    continue;
                }

                int count = 0;
                for (vector<int> &d : dir) {
                    int r = sr + d[0], c = sc + d[1];
                    if (r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size() ) {
                        count += dp[r][c];  // mazePath_memo(r, c, er, ec, dp, dir);
                    }
                }

                dp[sr][sc] = count;
            }
        }

        return dp[SR][SC];
    }

int uniquePaths(int m, int n) {
        vector<vector<int>> dp( n , vector<int> (m, -1));
        vector<vector<int>> dir = { { 1, 0 }, { 0, 1 } };
        return mazePath_tabu(0, 0, n - 1, m - 1, dp, dir);
}

// 63. Unique Paths II

int mazePath_tabuObstacle(int SR, int SC, int ER, int EC, vector<vector<int>> &dp, vector<vector<int>> &dir,vector<vector<int>> &obstacleGrid) {
        for (int sr = ER; sr >= SR; sr--) {
            for (int sc = EC; sc >= SC; sc--) {
                if (ER == sr && EC == sc) {
                    dp[sr][sc] = 1;
                    continue;
                }

                long count = 0;
                for (vector<int> &d : dir) {
                    int r = sr + d[0], c = sc + d[1];
                    if (r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size() && obstacleGrid[r][c] == 0) {
                        count += dp[r][c];  // mazePath_memo(r, c, er, ec, dp, dir);
                    }
                }

                dp[sr][sc] = count;
            }
        }

        return dp[SR][SC];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        vector<vector<int>> dp( n , vector<int> (m, -1));
        vector<vector<int>> dir = { { 1, 0 }, { 0, 1 } };
        return mazePath_tabuObstacle(0, 0, n - 1, m - 1, dp, dir, obstacleGrid);
    }

// 64. Minimum Path Sum

    int mazePath_tabu(int SR, int SC, int ER, int EC, vector<vector<int>> &dp, vector<vector<int>> &dir,vector<vector<int>>& grid) {
        for (int sr = ER; sr >= SR; sr--) {
            for (int sc = EC; sc >= SC; sc--) {
                if (sr == ER && sc == EC) {
                    dp[sr][sc] = grid[sr][sc];
                    continue;
                }
        
                int sum = INT_MAX;
                for (vector<int> &d : dir) {
                    int r = sr + d[0], c = sc + d[1];
                    if (r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size() ) {
                        sum = min(sum,grid[sr][sc] + dp[r][c]);
                    }
                }

                dp[sr][sc] = sum;
            }
        }

        return dp[SR][SC];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp( n , vector<int> (m, -1));
        vector<vector<int>> dir = { { 1, 0 }, { 0, 1 } };
        return mazePath_tabu(0, 0, n - 1, m - 1, dp, dir,grid);
    }

int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //assign the meaning to the dp matrix 
        //intialise the base cases in the dp matrix
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    dp[i][j]=grid[i][j];
                }else if(i==n-1){
                    dp[i][j]=dp[i][j+1]+grid[i][j];
                }else if(j==m-1){
                    dp[i][j]=dp[i+1][j]+grid[i][j];
                }else{
                    dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        //finally return the answer from the biggest subproblem 
        return dp[0][0];
        
    }

// 70. Climbing Stairs

int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            if(i == 1){
                dp[i] = dp[i-1];
            }else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }

int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            int sum = a + b;
            a = b;
            b = sum;
        }

        return b;
    }

// 746. Min Cost Climbing Stairs

int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N,-1);
        for(int n=0;n<N;n++){
            if(n <= 1){
                dp[n] = cost[n];
                continue;
            }

            int ans = min(dp[n-1],dp[n-2]) + cost[n];
            dp[n] = ans;
        }
        return min(dp[N-1],dp[N-2]);
    }

// Board Path.========================================================

int boardPath_memo(int sp, int ep, vector<int> &dp) {
        if (sp == ep) {
            return dp[sp] = 1;
        }

        if (dp[sp] != 0)
            return dp[sp];

        int count = 0;
        for (int dice = 1; dice <= 6 && sp + dice <= ep; dice++) {
            count += boardPath_memo(sp + dice, ep, dp);
        }

        return dp[sp] = count;
    }

int boardPath_tabu(int SP, int ep, vector<int> &dp) {
        for (int sp = ep; sp >= 0; sp--) {
            if (sp == ep) {
                dp[sp] = 1;
                continue;
            }

            int count = 0;
            for (int dice = 1; dice <= 6 && sp + dice <= ep; dice++) {
                count += dp[sp + dice];// boardPath_memo(sp + dice, ep, dp);
            }

            dp[sp] = count;
        }

        return dp[SP];
    }

