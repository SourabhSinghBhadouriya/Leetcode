#include<bits/stdc++.h>
using namespace std;

// 2305. Fair Distribution of Cookies

int getMax(vector<int>& distribution){
        int maxi = INT_MIN;
        for(int i=0; i<distribution.size(); i++)
            maxi = max(maxi, distribution[i]);
        return maxi;
    }

void f(int index, vector<int>& distribution, vector<int>& cookies, int& k, int& ans){
        // base condition - all cookies distributed
        if(index == cookies.size()){
            ans = min(ans, getMax(distribution));
            return;            
        }

        // Optimization / Pruning
        if(ans <= getMax(distribution))
            return;

        // try all possibilities
        for(int i=0; i<k; i++){
            distribution[i] += cookies[index];              // give to ith child
            f(index+1, distribution, cookies, k, ans);      // recurse for next index
            distribution[i] -= cookies[index];              // backtrack
        }
    }

int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> distribution(k, 0);
        // index, distribution, cookies, k , ans
        f(0, distribution, cookies, k, ans);
        return ans;
    }
