/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Input: n = 2
Output: 2
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int x=1;
        int y=2;
        if(n<=2)
        {
            return n;
        }
        for(int i=3;i<n;i++)
        {
            int temp=y;
            y=y+x;
            x=temp;
        }
        return (x+y);
          
        
    }
};
int main()
{
	Solution s;
	cout<<s.climbStairs(2);


	return 0;
}

