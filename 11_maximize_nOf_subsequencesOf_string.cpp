/*
You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.

You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.

Return the maximum number of times pattern can occur as a subsequence of the modified text.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Input: text = "abdcdbc", pattern = "ac"
Output: 4
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long find_ans(string text,string pattern)
    {
        int n = text.size();
        vector<long long>arr(n+1);
        
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(text[i]==pattern[1])
            {
                arr[i]=arr[i+1]+1;
            }
            else
            {
                arr[i]=arr[i+1];
            }
        }
        long long ans=0;
        for(i=0;i<n;i++)
        {
            if(text[i]==pattern[0])
            {
                ans = ans+arr[i+1];
            }
        }
        return ans;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        string s1,s2="";
        s1=pattern[0]+text;
        s2=text+pattern[1];
        return max(find_ans(s1,pattern),find_ans(s2,pattern));
        
    }
};
int main()
{
	Solution s;
	cout<<"ans = "<<s.maximumSubsequenceCount("abdcdbc","ac");
	return 0;
}

