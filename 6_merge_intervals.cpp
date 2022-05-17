/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
        {
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto it : intervals)
        {
            if(it[0]<=temp[1])
            {
                temp[1]=max(it[1],temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
int main()
{
	Solution s;
	vector<vector<int>>v;
	v.push_back({1,3});
	v.push_back({2,6});
	v.push_back({8,10});
	v.push_back({15,18});
	v = s.merge(v);
	for(auto it: v)
	{
	    cout<<it[0]<<"  "<<it[1]<<endl;
	}
	return 0;
}

