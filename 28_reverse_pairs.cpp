/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3

Approach 1: By brute force, Time complexity: O(N^2)
Approach 2: Using merge sort, Time complexity: O(NlogN+O(N)+O(N))
-->solution below
*/
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int merge(vector<int> &nums,int start,int mid,int end)
    {
        vector<int> temp(end - start + 1);
        
        int p = start;
        int q = mid + 1;
        int ans = 0;
        
        while(p <= mid){
            while(q <= end && (long long)nums[p] <= (long long)2 * nums[q]){
                q++;
            }
            ans += end + 1 - q;
            p++;
        }
        
        p = start;
        q = mid + 1;
        int r = 0;
        
        while(p <= mid && q <= end){
            if(nums[p] >= nums[q]){
                temp[r++] = nums[p++];
            }
            else{
                temp[r++] = nums[q++];
            }
        }
        
        while(p <= mid){
            temp[r++] = nums[p++];
        }
        
        while(q <= end){
            temp[r++] = nums[q++];
        }
        
        for(int i = start; i <= end; i++){
            nums[i] = temp[i - start];
        }
        return ans;
    }
    
    int mergesort(vector<int> &nums,int l,int h)
    {
        int ans = 0;
        if(l<h)
        {
            int k = (l+h)/2;
            ans+=mergesort(nums,l,k);
            ans+=mergesort(nums,k+1,h);
            ans+=merge(nums,l,k,h);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
int main()
{
	Solution s;
	vector<int>v ({1,3,2,3,1});
	cout<<s.reversePairs(v);
	return 0;
}

