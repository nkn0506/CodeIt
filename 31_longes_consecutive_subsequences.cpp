/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Approach 1: First sort the array then check the consecutive numbers and return the max length of consecutive subsequences
Time compelxity: O(NlogN)+O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i;
        int count=1,max_=1;
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int j=1;j<nums.size();j++)
        {
            if(nums[j]==nums[j-1])
            {
                continue;
            }
            if(nums[j]==nums[j-1]+1)
            {
                count++;
            }
            else
            {
                count=1;
            }
            max_=max(max_,count);
        }
        return max_;
    }
};

Approach 2: Using set by inserting elements in it and then check whether element+1 number exist or not
Time complexity: O(3N)
Solution-->
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i;
        set<int>s;
        for(i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int max_=0;
        for(int x : nums){
            int count=1;
            if(s.find(x-1) != s.end()){
                continue;
            }
            
            else{
                while(s.find(x+1) != s.end()){
                    count++;
                    x++;
                }
            }
            max_ = max(max_, count);
        }
        return max_;
    }
};
int main()
{
	Solution s;
	vector<int>v ({100,4,200,3,1,2});
	cout<<s.longestConsecutive(v);
	return 0;
}

