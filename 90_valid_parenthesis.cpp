/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
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
    bool isValid(string s) {
        stack<int> st;
        int i;
        for(i=0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')' && st.size() && st.top() == '(')
                st.pop();
            else if(s[i] == '}' && st.size() && st.top() == '{')
                st.pop();
            else if(s[i] == ']' && st.size() && st.top() == '[')
                st.pop();
            else
                return false;
        }
        return st.empty();
        
    }
};
int main()
{
	Solution s;
	if(s.isValid("[{()}]"))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}


	return 0;
}

