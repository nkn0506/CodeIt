/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
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
    int longestPalindrome(string s) {
        int i,ans=0;
        map<char,int> m;
        for(i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        int max_ = INT_MIN;
        int flag = 0;
        for(auto i:m)
        {
            if(i.second%2==0)
            {
                ans=ans+i.second;
            }
            else
            {
                ans=ans+i.second-1;
                flag=1;
            }
        }
        if(flag!=1)
        {
            return ans;
        }
        return ans+1;
    }
};


