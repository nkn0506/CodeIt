/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
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
    vector<vector<string>>ans;
      bool isPalindrome(string s){
        int i=0;
        int j= s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string &s, int index, vector<string> arr )
    {
        if(index==s.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            string temp = s.substr(index,i-index+1);
            if(isPalindrome(temp))
            {
                arr.push_back(temp);
                solve(s,i+1,arr);
                arr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<string>str;
        solve(s, 0 ,str );
        return ans;
        
    }
};
int main()
{
	Solution s;
	vector<vector<string>>ans;
	ans=s.partition("aabb");
	return 0;
}

