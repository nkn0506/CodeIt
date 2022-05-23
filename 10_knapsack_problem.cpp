/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity.
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W
E.g.,
val = {60,100,120}
wt = {10,20,30}
capacity = 50

Approach 1: Recursion by brute-force, Time complexity: O(2^n), space complexity: O(1)
//dividing the problem into subproblems
//1.Include the item   2. Exclude the item

//n = no of items, w = capacity
if(n==0 || w==0)
{
    return 0;
}
if(wt[n-1] > w)
{
    return knapSack(w,wt,val,n-1);
}
else
{ 
    return max(knapSack(w,wt,val,n-1), knapSack(w-wt[n-1],wt,val,n-1)+val[n-1]);
}

Approach 2: Using memoization
-->Below

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapSack(int w,int wt[],int val[],int i,int **dp)
{
	if(i<0) //If number of items 0
	{
		return 0;
	}
	if(dp[i][w]!=-1)
	{
		return dp[i][w];
	}
	if(wt[i]>w) //if weight of the item is greater than capacity of the bag
	{
		dp[i][w] = knapSack(w,wt,val,i-1,dp); //store the profit for the last item
	}
	else //if weight is less than the capacity
	{
		dp[i][w] = max(knapSack(w,wt,val,i-1,dp), val[i]+knapSack(w-wt[i],wt,val,i-1,dp));
	}
	
	return dp[i][w];
}
int main()
{
	int val[] = { 1,2,5,6 };
    int wt[] = { 2,3,4,5 };
    int w = 8;
    int n = sizeof(val) / sizeof(val[0]);
    int i,j;
    int **dp;
    dp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[w + 1];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < w + 1; j++)
            dp[i][j] = -1;

    cout << knapSack(w, wt, val, n-1,dp);
	return 0;
}

