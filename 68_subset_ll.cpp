/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<vector<int>>v;
    void find_ans(vector<int> &arr,int i,int n,vector<int> &s){
        if(i==n)
        {
            v.insert(s);
            return;
        }
        s.push_back(arr[i]);
        find_ans(arr,i+1,n,s);
        s.pop_back();
        find_ans(arr,i+1,n,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>s;
        vector<vector<int>>ans;
        int n = nums.size();
        find_ans(nums,0,n,s);
        for(auto &it: v)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};

