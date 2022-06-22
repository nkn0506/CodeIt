/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>fans;
    void find_ans(vector<int> &arr,int i,int target,int n,vector<int>& ans)
    {
        if(i==n)
        {
            if(target==0)
            {
                if(find(fans.begin(),fans.end(),ans)==fans.end())
                {
                    fans.push_back(ans);
                }
            }
            return;
        }
        if(target>=arr[i])
        {
            ans.push_back(arr[i]);
            find_ans(arr,i+1,target-arr[i],n,ans);
            ans.pop_back();
        }
        while(i+1 <arr.size() && arr[i] == arr[i+1]) i++;
        find_ans(arr,i+1,target,n,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> v;
        sort(arr.begin(),arr.end());
        find_ans(arr,0,target,arr.size(),v);
        return fans;    
    }
};
