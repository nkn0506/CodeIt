/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        int i;
        vector<vector<string>> ans;
        for(auto it: strs)
        {
            string temp = it;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
            //so map will look like
            //aet -> (eat,tea,ate)
            //ant -> (tan,nat)
            //abt -> (bat)
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};


