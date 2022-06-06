/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. 
If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.

Approach 1: next_permutation(), Time complexity: O(N*N!)
Approach 2-->
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end()); 
        int n = nums.size();
        if(nums.size()==1)
        {
            return;
        }
        int a,i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                a = i;
                break;
            }
        }
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            int b = 0;
            for(i=n-1;i>=0;i--)
            {
                if(nums[i]>nums[a])
                {
                    b = i;
                    break;
                }
            }
            swap(nums[a],nums[b]);
            reverse(nums.begin()+a+1,nums.end());
        }
        
    }
};
int main()
{
	Solution s;
	vector<int>v ({3,2,1});
	s.nextPermutation(v);
	for(int i=0;i<3;i++)
	{
		cout<<v[i]<<" ";
	}


	return 0;
}

