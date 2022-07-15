/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
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
    unordered_map<string,int>dp;
    int find_ans(string s,vector<string> &word)
    {
        int l = s.length();
        if(l==0)
        {
            return 1;
        }
        if(dp[s]!=0)
        {
            return dp[s];
        }
        for(int i=1;i<=l;i++)
        {
            int flag=0;
            string ss = s.substr(0,i);
            //now check if ss present in worddict
            for(int j=0;j<word.size();j++)
            {
                if(ss.compare(word[j])==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1 && find_ans(s.substr(i,l-i),word)==1)
                return dp[s]=1;
        }
        return dp[s]=-1;
    }
    bool wordBreak(string s, vector<string>& word) {
        if(find_ans(s,word)==1)
        {
            return true;
        }
        return false;
        
    }
};


