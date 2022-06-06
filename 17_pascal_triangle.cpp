/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Element of r-1 row, c-1 column =  (r-1)C(c-1)
                               Time complexity: O(N^2)
*/


#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        
        int i,j;
        for(i=0;i<n;i++)
        {
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(j=1;j<i;j++)
            {
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
        
    }
};
int main()
{
	Solution s;
	vector<vector<int>> vect;
	vect = s.generate(5);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }
	return 0;
}

