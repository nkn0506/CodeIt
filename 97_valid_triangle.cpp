/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.


Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4

Approach: Using two pointers and binary search
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int l,h,ans = 0;
        int i,n = nums.size();
        sort(nums.begin(),nums.end());
        for(i=n-1;i>=0;i--)
        {
            l = 0;
            h = i-1;
            while(l<h)
            {
                if(nums[l]+nums[h]>nums[i])
                {
                   ans = ans+(h-l);
                    h--;
                }
                else
                {
                    l++;
                }
            }  
        }
        return ans;
        
    }
};
int main()
{
	Solution s;
	vector<int>v ({5,4,3,2,1});
	cout<<s.triangleNumber(v);
	return 0;
}

