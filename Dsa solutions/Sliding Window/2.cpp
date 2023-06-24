#include<bits/stdc++.h>
#include <vector>
#include<string>
#include <iostream>
#include <list>
#include<unordered_map>
using namespace std;

// 3. Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int tail=0,head=0,ans=0;
        for(head=0;head<s.size();head++){
            while(mp[s[head]] > 0){
                mp[s[tail]]--;
                tail++;
            }
            mp[s[head]]++;
            ans = max(ans,head-tail+1);
        }
        return ans;
    }

// 1004. Max Consecutive Ones III

int longestOnes(vector<int>& nums, int k) {
        int head=0,tail=0,ans=0;
        for(head=0;head<nums.size();head++){
            if(nums[head] == 0)k--;
            while(k < 0){
                if(nums[tail] == 0)k++;
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
    }

// 1208. Get Equal Substrings Within Budget

int equalSubstring(string s, string t, int maxCost) {
        int head=0,tail=0,ans=0,cost=0;
        for(head=0;head<s.size();head++){
            cost += abs(s[head]-t[head]);
            while(cost > maxCost){
                cost -= abs(s[tail]-t[tail]);
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
    }

// 713. Subarray Product Less Than K

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)return 0;
        int head=0,tail=0,ans=0,product=1;
        for(head=0;head<nums.size();head++){
            product = product*nums[head] ;
            while(product >= k){
                product = product/nums[tail];
                tail++;
            }
            ans = ans + (head-tail+1);
        }
        return ans;
    }