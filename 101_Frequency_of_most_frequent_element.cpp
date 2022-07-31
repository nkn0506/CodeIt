/*
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.

Approach: Using sliding window and binary search
*/

#include<stdio.h>
#include<iostream>++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long ans = 1,sum=0;
        long l = 0;
        for(int h=0;h<nums.size();h++)
        {
              sum=sum+nums[h];
            
            //check how many operations needed to make elements same as last element of window from             //(l to h) range
            
            if(nums[h]*(h-l+1)-sum <= k)
            {
                ans=max(ans,(h-l+1));
                //h-l+1 = frequency
            }
            else
            {
                sum=sum-nums[l];
                l++;
            }
        }
        return ans;
        
        
    }
};


