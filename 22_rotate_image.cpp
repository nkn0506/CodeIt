/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Approach 1: Using brute force by making one more matrix, Time complexity: O(N^2)
Approach 2: By finding traspose of the matrix first and then reverse each row to rotate it finally-->
*/
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j;
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
int main()
{
	Solution s;
	vector<vector<int>>v {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    s.rotate(v);
	return 0;
}

