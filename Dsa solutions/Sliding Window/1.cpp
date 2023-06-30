#include<bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
        int tail=0,head=0,ans=0;   // declare global variables head,tail,ans
        unordered_map<char,int> mp;  // if necessary declare ds to store frequency(map,vector)
        for(head=0;head<s.size();head++){  // run for loop for whole array
            mp[s[head]]++;   // make operation
            while(mp[s[head]] > 1){   // while loop for condition fail
                mp[s[tail]]--;   // remove tail/last element
                tail++;   // increase tail/update tail
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

// 1695. Maximum Erasure Value

int maximumUniqueSubarray(vector<int>& nums) {
        int tail=0,head=0,ans=0,sum=0;   
        unordered_map<int,int> mp; 
        for(head=0;head<nums.size();head++){  
            mp[nums[head]]++;   
            while(mp[nums[head]] > 1){   
                sum -= nums[tail];
                mp[nums[tail]]--;
                tail++;  
            }
            if(mp[nums[head]] == 1)sum += nums[head];
            ans = max(ans,sum);  
        }
        return ans;
    }

// 424. Longest Repeating Character Replacement

int characterReplacement(string s, int k) {
        int head=0,tail=0,ans=0;
        vector<int> freq(26,0);
        for(head=0;head<s.size();head++){
            freq[s[head]-'A']++;
            while(head-tail+1 - *max_element(freq.begin(),freq.end()) > k){
                freq[s[tail]-'A']--;
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
    }

// 209. Minimum Size Subarray Sum

int minSubArrayLen(int target, vector<int>& nums) {
        int head=0,tail=0,ans=INT_MAX,sum=0;
        for(head=0;head<nums.size();head++){
            sum+=nums[head];
            while(sum >= target){
                ans=min(ans,head-tail+1);
                sum-=nums[tail];
                tail++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

// 1658. Minimum Operations to Reduce X to Zero

// 2024. Maximize the Confusion of an Exam

int maxConsecutiveAnswers(string s, int k) {
        int head=0,tail=0,cntt=0,cntf=0,mxans=0;
        for(head=0;head<s.size();head++){
            if(s[head] == 'T')cntt++;
            if(s[head] == 'F')cntf++;

            while(min(cntt,cntf) > k){
                if(s[tail] == 'T')cntt--;
                if(s[tail] == 'F')cntf--;
                tail++;
            }
            mxans = max(mxans,head-tail+1);
        }
        return mxans;
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

// 904. Fruit Into Baskets

int totalFruit(vector<int>& fruits) {
        int tail=0,head=0,ans=0;   
        unordered_map<int,int> mp; 
        for(head=0;head<fruits.size();head++){  
            mp[fruits[head]]++;   
            while(mp.size() > 2){   
                mp[fruits[tail]]--; 
                if(mp[fruits[tail]] == 0)mp.erase(fruits[tail]);
                tail++;  
            }
            ans = max(ans,head-tail+1);  
        }
        return ans;  
    }


// 2260. Minimum Consecutive Cards to Pick Up

int minimumCardPickup(vector<int>& cards) {
        int tail=0,head=0,ans=INT_MAX;   
        unordered_map<int,int> mp; 
        for(head=0;head<cards.size();head++){  
            mp[cards[head]]++;   
            while(mp[cards[head]] > 1){  
                ans = min(ans,head-tail+1);  
                mp[cards[tail]]--; 
                tail++;  
            } 
        }
        return ans == INT_MAX ? -1 : ans; 
    }


// 2348. Number of Zero-Filled Subarrays

long long zeroFilledSubarray(vector<int>& nums) {
        long long head=0,tail=0,ans=0;
        for(head=0;head<nums.size();head++){
            tail = head;
            while(head < nums.size() && nums[head] == 0){
                ans += (head-tail+1);
                head++;
            }
        }
        return ans;
    }

// 2110. Number of Smooth Descent Periods of a Stock

long long getDescentPeriods(vector<int>& prices) {
        long long head=0,tail=0,ans=0;
        for(head=1;head<prices.size();head++){
            while(head < prices.size() && prices[head] - prices[head-1] == -1){
                ans += (head-tail+1)-1;
                head++;
            }
            tail = head;
        }
        return ans + prices.size();
    }




