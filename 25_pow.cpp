/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Approach 1: Using pow(x,y) function, Time complexity: O(logN)

Approach 2: Using brute force by looping from 1 to n, Time complexity: O(N)
            In case, when n is negative it will overflow as we take abs of n and then 1/x^n
            That's why by taking abs of -n, the range will be 2,147,483,648.

Approach 3: -->
*/

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        // double ans = pow(x,n);
        // return ans;
        long s = n;
        double ans=1;
        if(s<0)
        {
            s = (-1)*s;
        }
        while(s>0)
        {
            if(s%2==0)
            {
                x = x*x;
                s=s/2;
            }
            else
            {
                ans = ans*x;
                s=s-1;
            }
        }
        if(n<0)
        {
            ans = (double)1.0/(double)ans;
        }
        return ans;
        
    }
};
int main()
{
	Solution s;
	cout<<s.myPow(5,10)<<endl;
	cout<<s.myPow( 2.10000,-2);
	return 0;
}

