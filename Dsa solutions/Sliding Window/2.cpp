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
                ans = max(ans,head-tail);
                mp[s[tail]]--;
                tail++;
            }
            mp[s[head]]++;
        }
        return max(ans,head-tail);
    }