/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

Approach 1: When we find 0, we can mark the entire row and column zero in new array.
            Time complexity: O(MN)
Approach 2: We can make 2 arrays with size of no of rows and columns respectively.
            If matrix element is zero then make corresponding index of rows and columns zero in newly made 2 arrays.
            Time complexity: O(M+N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>row(r,1),col(c,1);
        int i,j;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(row[i]==0 || col[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};

Approach 3: Instead of making two different arrays, we can use 1st row and column to store zero information
            Constant space solution
            -->
*/



#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
        {
            return;
        }
        int i,j;
        int r = matrix.size();
        int c = matrix[0].size();
        
        bool frow = false, fcol = false;
        
        //check first row and column whether it contain zero or not
        for(i=0;i<c;i++)
        {
            if(matrix[0][i]==0)
            {
                frow = true;
            }
        }
        for(i=0;i<r;i++)
        {
            if(matrix[i][0]==0)
            {
                fcol = true;
            }
        }
        for(i=1;i<r;i++)
        {
            for(j=1;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(i=1;i<r;i++)
        {
            for(j=1;j<c;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(frow==true)
        {
            for(i=0;i<c;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(fcol==true)
        {
            for(i=0;i<r;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
        
        
};
int main()
{
	Solution s;
	vector<vector<int>>v 
	{
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
    };
    s.setZeroes(v);
	for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }
	return 0;
}

