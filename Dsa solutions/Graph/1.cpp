#include<bits/stdc++.h>
using namespace std;

// 997. Find the Town Judge

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1,0);
        vector<int> outdeg(n+1,0);
        for(auto i: trust){
            outdeg[i[0]]++;
            indeg[i[1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(indeg[i] == n-1 && outdeg[i] == 0){
                ans=i;
                break;
            }
        }
        return ans;
    }