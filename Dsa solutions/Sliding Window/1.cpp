#include<bits/stdc++.h>
#include <vector>
#include<string>
#include <iostream>
#include <list>
#include<unordered_map>
using namespace std;

// 567. Permutation in String

bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        
        vector<int>freq1(26, 0), freq2(26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (freq1 == freq2)
                return true;
            freq2[s2[i + s1.size()] - 'a']++;
            freq2[s2[i] - 'a']--;
        }
        
        return (freq1 == freq2);
    }

// 438. Find All Anagrams in a String

vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }

        vector<int>freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < p.size(); i++) {
            freq1[s[i] - 'a']++;
            freq2[p[i] - 'a']++;
        }

        vector<int>ans;
        for (int i = 0; i < s.size()-p.size(); i++) {
            if (freq1 == freq2) {
                ans.push_back(i);
            }
            freq1[s[i]-'a']--;
            freq1[s[i + p.size()] - 'a']++;
        }
        if (freq1 == freq2) {
            ans.push_back(s.size() - p.size());
        }
        return ans;
    }

// 1456. Maximum Number of Vowels in a Substring of Given Length

int maxVowels(string s, int k) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        int countInCurrWindow = 0;
        for (int i = 0; i < k; i++) {
            countInCurrWindow += vowels.count(s[i]);
        }

        int ans = countInCurrWindow;

        for (int i = k; i < s.size(); i++) {
            countInCurrWindow += vowels.count(s[i]) - vowels.count(s[i-k]);
            ans = max(ans, countInCurrWindow);
        }

        return ans;
    }

// 