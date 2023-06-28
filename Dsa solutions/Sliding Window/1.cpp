#include<bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
        int tail=0,head=0,ans=0;   // declare global variables head,tail,ans
        unordered_map<char,int> mp;  // declare ds to store frequency(map,vector)
        for(head=0;head<s.size();head++){  // run for loop
            mp[s[head]]++;   // make operation
            while(mp[s[head]] > 1){   // while loop for condition fail
                mp[s[tail]]--;   // remove tail/last element
                tail++;   // increase tail
            }
            ans = max(ans,head-tail+1);  // store ans
        }
        return ans;  // return ans
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

// 567. Permutation in String

bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }
        int sz = s1.size();
        int head=0,tail=0;
        for(head=0;head<s2.size();head++){
            if(freq1 == freq2)return true;
            while(head-tail+1 > sz){
                freq2[s2[tail]-'a']--;
                tail++;
            }
            freq2[s2[head]-'a']++;
        }
        return (freq1 == freq2);
    }

// 438. Find All Anagrams in a String

vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int>freq1(26, 0), freq2(26, 0);
        for(int i=0;i<p.size();i++){
            freq2[p[i] - 'a']++;
        }
        int sz = p.size();
        int head=0,tail=0;
        for(head=0;head<s.size();head++){
            if(freq1 == freq2)ans.push_back(tail);
            while(head-tail+1 > sz){
                freq1[s[tail]-'a']--;
                tail++;
            }
            freq1[s[head]-'a']++;
        }
        if(freq1 == freq2)ans.push_back(tail);
        return ans;
    }

// 1456. Maximum Number of Vowels in a Substring of Given Length

bool isVowel( char c ){
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int head=0,tail=0,ans=0,count=0;
        for(head=0;head<s.size();head++){
            if( isVowel(s[head])) count++;
            while(head-tail+1 > k){
                if( isVowel(s[tail])) count--;
                tail++;
            }
            ans = max(ans,count);
        }
        return ans;
    }

// 2302. Count Subarrays With Score Less Than K

long long countSubarrays(vector<int>& nums, long long k) {
        long long head=0,tail=0,ans=0,sum=0;
        for(head = 0;head<nums.size();head++){
            sum += nums[head];
            while(sum*(head-tail+1) >= k){
                sum -= nums[tail];
                tail++;
            }
            ans += (head-tail+1);
        }
        return ans;
    }