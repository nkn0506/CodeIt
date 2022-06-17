/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Time complexity: O(N*N)
Space complexity: O(M)
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j;
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3)
        {
            return ans;
        }
        sort(nums.begin(),nums.end());
        
        for(i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            
            int temp=nums[i];
            int l=i+1;
            int r=n-1;
            
            while(l<r)
            {
                int sum=temp+nums[l]+nums[r];
                if(sum>0)
                {
                    r--;
                    if(nums[r]==nums[r+1])
                    {
                        continue;
                    }
                }
                else if(sum<0)
                {
                    l++;
                    if(nums[l]==nums[l-1])
                    {
                        continue;
                    }
                }
                else
                {
                    if(l>i+1 && nums[l]==nums[l-1])
                    {
                        l++;
                        continue;
                    }
                    vector<int> sum={temp,nums[l],nums[r]};
                    ans.push_back(sum);
                    l++;
                }
            }
        }
        return ans;
        
    }
};


