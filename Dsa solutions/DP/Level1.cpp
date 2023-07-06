#include<bits/stdc++.h>
using namespace std;


// Fibonacci-dp
int FibMemoized(int n,vector<int> dp){
    if(n == 0 || n == 1){
        return n;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    int fibnm1 = FibMemoized(n-1,dp);
    int fibnm2 = FibMemoized(n-2,dp);
    int fibn = fibnm1 + fibnm2;

    dp[n] = fibn;
    return fibn;

}
int fib(int n){
    vector<int> dp(n+1,-1);
    return FibMemoized(n,dp);
}

// Climb Stairs

int cs(int n){
    vector<int> dp(n+1,-1);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            if(i == 1){
                dp[i] = dp[i-1];
            }else if(i == 2){
                dp[i] = dp[i-1] + dp[i-2];
            }else{
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
        }
        return dp[n];
}

int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                dp[i] = dp[i+1] ;
            }else{
                dp[i] = dp[i+1] + dp[i+2];
            }
        }
        return dp[0];
    }

// Climb Stairs With Variable Jumps

int cs(vector<int> arr, int n){
    vector<int> dp(n+1,-1);
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=arr && i+j<dp.size();j++){
            dp[i] += dp[i+j];
        }
    }
    return dp[0];
}
