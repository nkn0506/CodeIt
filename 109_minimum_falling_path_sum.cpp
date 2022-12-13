/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
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

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[101][101];
        int i,j;
        //store the 1st col values in dp matrix as it is
        for(i=0;i<m;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        //start storing other remaining values with min values
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int min_ = 56000;
                if(i-1>=0)
                {
                    min_ = min(min_,dp[i-1][j]);
                }
                if(i-1>=0 && j+1<m)
                {
                    min_ = min(min_,dp[i-1][j+1]);
                }
                if(i-1>=0 && j-1>=0)
                {
                    min_ = min(min_,dp[i-1][j-1]);
                }
                dp[i][j] = min_+matrix[i][j];
            }
        }

        int ans = dp[n-1][0];
        for(i=1;i<m;i++)
        {
            ans = min(ans,dp[n-1][i]);
        }

        return ans;
    }
};


