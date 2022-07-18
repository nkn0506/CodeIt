/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Approach: Using sliding window
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
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(n<m)
        {
            return {};
        }
        
        vector<int> arr(26,0);
        vector<int>window(26,0);
        
        vector<int>ans;
        int i;
        for(i=0;i<m;i++)
        {
            arr[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        if(arr==window)
        {
            ans.push_back(0);
        }
        
        for(i=m;i<n;i++)
        {
            window[s[i-m]-'a']--;
            window[s[i]-'a']++;
            
            if(arr==window)
            {
                ans.push_back(i-m+1);
            }
        }
        return ans;
        
    }
};

