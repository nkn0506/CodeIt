/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void find_ans(vector<int> &arr,int i,int n,vector<int> &v)
    {
        if(i==n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(arr[i]);
        find_ans(arr,i+1,n,v);
        v.pop_back();
        find_ans(arr,i+1,n,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        find_ans(nums,0,nums.size(),arr);
        return ans;
    }
};
int main()
{
	Solution s;
	vector<int>v ({1,2,3});
	v = s.subsets(v);
	return 0;
}

