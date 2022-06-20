/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

//firstly make array having length=amount+1, coz we are finding minimum coins required. So there are no coins then it return amount greater than actual amount and ans will be -1.
//then find number of coins for each amount from 1 to 12 and store it in dp array.
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1,amount+1);
       int i,n = coins.size();
        dp[0]=0;
       for(i=1;i<=amount;i++){
           for(auto &c: coins)
           {
               if(c<=i){
                   dp[i]=min(dp[i],dp[i-c]+1);
                } 
           }
       }
       if(dp[amount]>amount){
           return -1;
       }
        return dp[amount];    
    }
};
int main()
{
	Solution s;
	vector<int>v ({1,2,5});
	cout<<s.coinChange(v,12);
	return 0;
}

