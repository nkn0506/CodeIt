/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Uisng hashmap, Time complexity: O(NlogN)
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& v) {
        sort(v.begin(),v.end(),cmp);
        int i,j;
        unordered_map<string,int>m;
        int ans = 0;
        for(i=0;i<v.size();i++){
            m[v[i]]=1;
            for(j=0;j<v[i].size();j++){
                string temp = v[i].substr(0,j)+v[i].substr(j+1);
                if(m.find(temp)!=m.end()){
                       m[v[i]] = max(m[v[i]],m[temp]+1);
                }
                   ans = max(ans,m[v[i]]);
            }
        }
                   return ans;
                     
        
    }
};
int main()
{
	Solution s;
	vector<string> v({"a","b","ba","bca","bda","bdca"});
	cout<<s.longestStrChain(v);
	return 0;
}

