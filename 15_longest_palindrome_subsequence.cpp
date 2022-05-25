/*Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
Input: s = "bbbab"
Output: 4

1 <= s.length <= 1000
s consists only of lowercase English letters.

//If there are palindrome subsequences present in the string then that subsequences must be present in the reverse of that string
//That means given string and reverse of that string must have common subsqeuences
//Hence we can apply LCS algorithm to find longest palindrome subsequence
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1005][1005];
    int find_ans(string &s,string &t,int i,int j,int n)
    {
       if(i >= n || j >= n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = 1 + find_ans(s, t, i + 1, j + 1, n);
        
        else
            return dp[i][j] = max(find_ans(s, t, i + 1, j, n), find_ans(s, t, i, j + 1, n));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string str=s;
        reverse(str.begin(),str.end());
        return find_ans(s,str,0,0,s.size());
        
    }
};
int main()
{
	Solution s;
	cout<<s.longestPalindromeSubseq("bbbab");


	return 0;
}

