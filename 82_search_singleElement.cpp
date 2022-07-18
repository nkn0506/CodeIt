/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

Approach 1: Naive approach: using xor operator
         int i;
         int ans = 0;
         for(i=0;i<nums.size();i++){
             ans = ans^nums[i];
         }
         return ans;
        
        Time complexity: O(N)
        Space complexity: O(1)

Approach 2: Using binary search
       Time complexity: O(logn)
       space complexity: O(1)
       
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
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        int mid;
        
        while(low<=high)
        {
            mid = (high+low)/2;
            if(mid%2==0)
            {
                if(nums[mid]!=nums[mid+1]) 
                {
                    //that means there is problem in left half so move high to mid-1
                    high=mid-1;
                }
                else
                {
                    //that means there is no problem in left half
                    low = mid+1;
                }
            }
            else if(mid%2!=0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            
        }
        return nums[low];  
    }
};
int main()
{
	Solution s;
	vector<int>v ({1,1,2,3,3,4,4,5});
	cout<<s.singleNonDuplicate(v);


	return 0;
}

