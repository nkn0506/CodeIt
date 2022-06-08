/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Approach 1: Brute force by taking three pointers i=0, j=i+1, k=j+1Time complexity: O(N^3logN)+O(logN)

Approach 2: Using two pointers i,j and left=j+1, right = n-1
Time complexity: O(N^3)
solution:-->
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()==0)
        {
            return ans;
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int target1 = target-nums[i]-nums[j];
                
                int left = j+1;
                int right = n-1;
                
                while(left<right)
                {
                    int rem_sum = nums[left]+nums[right];
                    if(rem_sum<target1)
                    {
                        left++;
                    }
                    else if(rem_sum>target1)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int>v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[left];
                        v[3]=nums[right];
                        ans.push_back(v);
                        
                        //ignore duplicate elements and shift to next
                        while(left<right && nums[left]==v[2])
                        {
                            left++;
                        }
                        while(left<right && nums[right]==v[3])
                        {
                            right--;
                        }
                    }
                }
                while(j+1<n && nums[j+1]==nums[j])
                {
                    j++;
                }
            }
            while(i+1<n && nums[i+1]==nums[i])
            {
                i++;
            }
        }
        return ans;
        
    }
};
int main()
{
	Solution s;
	vector<int>v ({1,0,-1,0,-2,2});
	vector<vector<int>>ans;
	ans = s.fourSum(v);
	return 0;
}

