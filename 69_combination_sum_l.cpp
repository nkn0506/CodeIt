
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fans;
    void find_ans(vector<int> &arr, int i,int target,int n,vector<int> & ans)
    {
        if(i==n)
        {
            if(target==0)
            {
                fans.push_back(ans);
            }
            
            return;
        }
        
        if(target>=arr[i])
        {
            ans.push_back(arr[i]);
            find_ans(arr,i,target-arr[i],n,ans);
            ans.pop_back();
        }
     
        find_ans(arr,i+1,target,n,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        int n = candidates.size();
        find_ans(candidates,0,target,n,ans);
        return fans;
    }
};
