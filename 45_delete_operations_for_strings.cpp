/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
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
    int dp[501][501];
    int LCS(string s, string t,int i,int j,int n,int m){
        if(i>=n || j>=m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j] = 1+LCS(s,t,i+1,j+1,n,m);
        }
        else
        {
            return dp[i][j] = max(LCS(s,t,i+1,j,n,m),LCS(s,t,i,j+1,n,m));
        }
        
    }
        
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return word1.size()+word2.size()-(2*LCS(word1,word2,0,0,word1.size(),word2.size()));  
        //LCS = lowest common subsequence
        
    }
};
int main()
{
	Solution s;
	cout<<s.minDistance("sea","eat");
	return 0;
}

