/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
Input: text1 = "abcde", text2 = "ace" 
Output: 3

Approach 1: Using recursion  Time complexity: O(2^N)
class Solution {
public:
    int find_ans(string s,string t,int i,int j)
    {
        if(s[i]=='\0' || t[i]=='\0')
        {
            return 0;
        }
        if(s[i]==t[j])
        {
            return 1+find_ans(s,t,i+1,j+1);
        }
        return max(find_ans(s,t,i+1,j),find_ans(s,t,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return find_ans(text1,text2,0,0);
        
    }
};

Approach 1: Memoization implementation
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1001][1001];
    
    int find_ans(string &str1, string &str2, int i, int j, int n1, int n2)
    {
        if(i >= n1 || j >= n2)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(str1[i] == str2[j])
            return dp[i][j] = 1 + find_ans(str1, str2, i + 1, j + 1, n1, n2);
        
        else
            return dp[i][j] = max(find_ans(str1, str2, i + 1, j, n1, n2), find_ans(str1, str2, i, j + 1, n1, n2));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return find_ans(text1, text2, 0, 0, text1.size(), text2.size());
    }
};
int main()
{
	Solution s;
	cout<<"ans = "<<s.longestCommonSubsequence("abcde","ace");
	return 0;
}

