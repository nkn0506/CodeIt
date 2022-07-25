/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Approach 1:
Using stack: Time complexity: O(N)
1. Find the left limit and right limit for each bar
2. Then find area for each bar using left and right limit
3. Calculate max area from them

(Left limit means smaller element in the left of given bar and
right limit means smaller limit in the right side of the given bar)
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s; 
        vector<int> left_bound(n,0),right_bound(n,n); 
        for(int i=0;i<n;i++) {
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            if(s.empty())  left_bound[i]=0;
            else  left_bound[i] = s.top()+1;
			
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--)  {
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            if(s.empty()) right_bound[i] = n-1;
            else  right_bound[i] = s.top()-1;
            s.push(i);
        }
        int maxi = 0, area;
        for(int i=0; i<n; i++) {
            area = (right_bound[i]-left_bound[i]+1)*heights[i];
            maxi = max(maxi, area);
        }
        return maxi;     
    }
};
int main()
{
	Solution s;
	vector<int>v ({2,1,5,6,2,3});
	cout<<s.largestRectangleArea(v);
	return 0;
}

