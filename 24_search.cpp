/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Approach 1: Using brute force by traversing lineraly in matrix

Approach 2: Using binary search, Time complexity: N*O(log m)


*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find_ans(vector<int>& mat,int l,int h, int target)
    {
        int i=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(mat[mid]==target)
            {
                return true;
            }
            else if(mat[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>final_arr;
        int i;
        for(i=0;i<matrix.size();i++)
        {
            int l=0,h=matrix[i].size()-1;
            if(target>=matrix[i][l] && target<=matrix[i][h])
            {
                return find_ans(matrix[i],0,matrix[i].size()-1,target);
            }
        }
        return false;
    }
};
int main()
{
	Solution s;
	vector<vector<int>> v {
		{ 1,3,5,7},
		{10,11,16,20},
		{23,30,34,60}	
	};
    s.searchMatrix(v,16);
	return 0;
}

