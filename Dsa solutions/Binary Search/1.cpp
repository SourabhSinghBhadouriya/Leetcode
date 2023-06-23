#include<bits/stdc++.h>
using namespace std;

// 704. Binary Search

int search(vector<int>& nums, int target) {
        int s = 0,e = nums.size()-1;
        while(s <= e){
            int  mid = s+(e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }

// Floor in a Sorted Array

int findFloor(vector<long long> v, long long n, long long x){
        int low = 0;
        int high = n-1;
        int floorIndex = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(v[mid]==x)
                return mid;
            else if(v[mid]<x)
            { 
                floorIndex = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return floorIndex;
    }

// 35. Search Insert Position(lower bound)

int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        int ans = nums.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

// 34. Find First and Last Position of Element in Sorted Array
// lower bound means smallest i for which arr[i] >= x
// upper bound means largest i for which arr[i] > x

int lowerBound(vector<int> arr, int n,int x){
        int low = 0,high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> arr, int n,int x){
        int low = 0,high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,n,target);
        if(lb == n || nums[lb] != target)return {-1,-1};
        return {lb , upperBound(nums,n,target) - 1} ;
    }