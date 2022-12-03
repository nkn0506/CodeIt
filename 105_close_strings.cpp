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
    bool closeStrings(string w1, string w2) {
        vector<int>v1(26,0),v2(26,0),v3(26,0),v4(26,0);
        int i;
        for(auto x:w1)
        {
            v1[x-'a']++;
            v3[x-'a']=1;
        }
        for(auto x:w2)
        {
            v2[x-'a']++;
            v4[x-'a']=1;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return (v1==v2) && (v3==v4);
    }
        
    
};
int main()
{
	Solution s;
	if(s.closeStrings("abc","bca"))
	{
		cout<<"strings are close";
	}
	else
	{
		cout<<"strings are not close";
	}
	
	return 0;
}

