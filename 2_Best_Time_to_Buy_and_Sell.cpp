/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Input: prices = [7,1,5,3,6,4]
Output: 5
*/
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
        int maxProfit(int prices[]) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < 5; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};
int main()
{
	Solution s;
	int num[5];
	for(int i=0;i<5;i++)
	{
		cin>>num[i];
	}
	cout<<"ans = "<<s.maxProfit(num);
	


	return 0;
}

