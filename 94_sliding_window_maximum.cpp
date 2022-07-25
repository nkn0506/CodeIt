/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
 Approach 1: Using brute force
        // int i,j;
        // vector<int>ans;
        // if(nums.size()==1)
        // {
        //     ans.push_back(nums[0]);
        //     return ans;
        // }
        // for(i=0;i<nums.size()-(k-1);i++)
        // {
        //     j=i;
        //     int max_ = nums[i];
        //     int c = 0;
        //     while(true)
        //     {
        //         if(c==k)
        //         {
        //             break;
        //         }
        //         max_ = max(max_,nums[j]);
        //         j++;
        //         c++;
        //     }
        //     ans.push_back(max_);
        // }
        // return ans;
 Approach deque: Time complexity: O(N)
                 Space complexity: O(K)
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        deque<int>dq;
        int i;
        vector<int>ans;
        for(i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            //if in the range of slidng window then only push
            
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
        
    }
};

