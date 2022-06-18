/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
*/


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length()!=s.length())
        {
            return false;
        }
        string str1 = s+s;
        if(str1.find(goal) != string::npos)
        {
            return true;
        }
        return false;
        
    }
};
int main()
{
	Solution s;
	cout<<s.rotateString("sample","plesa");
	return 0;
}

