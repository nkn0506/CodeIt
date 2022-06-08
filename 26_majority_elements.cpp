/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ?n / 2? times. You may assume that the majority element always exists in the array.


Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
Approach 1: Using brute force, Time complexity: O(N^2)
Approach 2: Using map, Time complexity: O(NlogN)
Approach 3: Using moore'voting algorithm O(N) -->
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0;
        int count = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                can = nums[i];
            }
            if(can==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return can;
    }
};
int main()
{
	Solution s;
	vector<int>v ({2,2,2,1,4,5,2,4,4});
	cout<<s.majorityElement(v);
	return 0;
}

