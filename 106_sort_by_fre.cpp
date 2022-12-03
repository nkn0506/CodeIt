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
    
    string frequencySort(string s) {
        map<char,int>m;
        for(auto i:s)
        {
            m[i]++;
        }
        vector<pair<char,int>>v;
        for(auto i:m)
        {
            v.push_back(i);
        }
        sort(v.begin(),v.end(),[](pair<char,int>&a,pair<char,int>&b){return a.second>b.second;});
        string ans="";
        for(auto i:v)
        {
            for(int j=0;j<i.second;j++)
            {
                ans+=i.first;
            }
        }
        return ans;
        
    }
};
int main()
{
	Solution s;
	cout<<"sorted string = "<<s.frequencySort("tree");
	return 0;
}

