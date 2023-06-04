#include<bits/stdc++.h>
using namespace std;

// 1791 Find Center of Star Graph

int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        for(auto &edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int ans = 1;
        int n = degree.size();
        for(auto &p : degree){
            if(p.second == n-1)
                ans = p.first;
        }
        return ans;
    }