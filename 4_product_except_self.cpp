/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        vector<int> ans;
        if(n<1)
        {
            return ans;
        }
        int p1=1;
        for(i=0;i<n;i++)
        {
            p1=p1*nums[i];
            ans.push_back(p1);
        }
        
        p1=1;
        for(i=n-1;i>0;i--)
        {
            ans[i]=ans[i-1]*p1;
            p1=p1*nums[i];
        }
        ans[0]=p1;
        
        return ans;
    }
};
int main()
{
	Solution s;
	vector<int>num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num = s.productExceptSelf(num);
	for(int i=0;i<num.size();i++)
	{
		cout<<num[i]<<"  ";
	}
	return 0;
}

