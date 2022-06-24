/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>>ans;
    void find_ans(int col,vector<string> &chess, vector<int> &leftrow,vector<int> &upperdia,vector<int> &lowerdia,int n)
    {
        if(col==n)
        {
            ans.push_back(chess);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && upperdia[(n-1)+col-row]==0 && lowerdia[row+col]==0)
            {
                chess[row][col]='Q';
                leftrow[row]=1;
                upperdia[n-1+col-row]=1;
                lowerdia[row+col]=1;
                find_ans(col+1,chess,leftrow,upperdia,lowerdia,n);
                chess[row][col]='.';
                leftrow[row]=0;
                upperdia[n-1+col-row]=0;
                lowerdia[row+col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> chess(n);
        string s(n,'.');
        int i;
        for(i=0;i<n;i++)  //for making of chessboard
        {
            chess[i]=s;
        }
        vector<int> leftrow (n,0),upperdia(2*n-1,0),lowerdia(2*n-1,0);
        find_ans(0,chess,leftrow,upperdia,lowerdia,n);
        return ans.size();
        
    }
};
