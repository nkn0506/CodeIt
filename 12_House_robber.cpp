/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        vector<int>dp(n); //dp array
        if(n>=1)
        {
            dp[0]=nums[0];  //store dp[0] as 1st element
        }
        if(n>=2)
        {
            dp[1]=max(nums[0],nums[1]); //store max from 1st and 2nd element
        }
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],(dp[i-2]+nums[i]));  
        }
        return dp[n-1];
    }
    
};
int main()
{
	Solution s;
	vector<int>v({2,7,9,3,1});
	cout<<"Ans = "<<s.rob(v);
	return 0;
}

