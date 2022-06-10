/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Approach 1: Naive approach, Time complexity: O(N^2)

Approach 2: Using set, Time complexity: O(2N)
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        set<char> s;
        int l=0,r=0,max_=0;
        while(l<str.length())
        {
            if(s.find(str[l])==s.end())
            {
                max_=max(max_,l-r+1);
                s.insert(str[l]);
                l++;
            }
            else
            {
                s.erase(str[r]);
                r++;
            }
        }
        
        return max_;
    }
};

Approach 3:Using hashmap and sliding window algorithm
Time complexity: O(N)
-->
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        map<char,int>m;
        int l=0,r=0,max_=0;
        while(r<str.length())
        {
            if(m.find(str[r])!=m.end())
            {
                l=max(l,m[str[r]]+1);
            }
            m[str[r]]=r;
            max_=max(max_,r-l+1);
            r++;
        }
        
        return max_;
    }
};
int main()
{
	Solution s;
	cout<<s.lengthOfLongestSubstring("abcaabcdba");
	return 0;
}

