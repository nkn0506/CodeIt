/*
Given an integer array of size n, find all elements that appear more than ? n/3 ? times.
Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int num1 = 0, c1 = 0;
            int num2 = 0, c2 = 0;
            
            for(int i = 0; i <  v.size(); i++)
            {
                if(v[num1] == v[i])
                    c1++;
                else if(v[num2] == v[i])
                    c2++;
                else if(c1 == 0)
                {
                    num1 = i;
                    c1 = 1;
                }
                else if(c2 == 0)
                {
                    num2 = i;
                    c2 = 1;
                } 
                else
                {
                    c1--;
                    c2--;
                }
            }

            c1 = c2 = 0;
            vector<int> ans;
            for(int i = 0; i < v.size(); i++)
            {
                if(v[num1] == v[i])
                    c1++;
                else if(v[num2] == v[i])
                    c2++;
            }

            if(c1 > (v.size())/3)
               ans.push_back(v[num1]);
            if(c2 > (v.size())/3)
                ans.push_back(v[num2]);

            return ans;
        
        
    }
};
int main()
{
	Solution s;
	vector<int>v ({3,3,3,2,5,2,1});
	v = s.majorityElement(v);
	return 0;
}

