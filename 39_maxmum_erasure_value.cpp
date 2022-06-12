/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>m;
        int i=0,j=0,sum=0,max_=0;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            sum=sum+nums[i];
            while(m[nums[i]]>1)
            {
                m[nums[j]]--;
                sum=sum-nums[j];
                j++;    
            }
            max_ = max(max_,sum);
        }
        return max_;        
    }
};
int main()
{
	Solution s;
	vector<int>v ({4,2,4,5,6});
	cout<<s.maximumUniqueSubarray(v);
	return 0;
}

