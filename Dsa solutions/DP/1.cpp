#include<bits/stdc++.h>
using namespace std;

// 62. Unique Paths

int mazePath_tabu(int SR, int SC, int ER, int EC, vector<vector<int>> &dp, vector<vector<int>> &dir) {
        for (int sr = ER; sr >= SR; sr--) {
            for (int sc = EC; sc >= SC; sc--) {
                if (ER == sr && EC == sc) {
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

