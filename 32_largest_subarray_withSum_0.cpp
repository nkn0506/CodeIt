/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Approach 1: Generating subarrays and return the max length of subarray having sum zero
Time complexity: O(N^3)

Approach 2: Using hashmap, Time complexity: O(NlogN) ..... (logN) for hashmap
*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        map<int,int>m;
        int sum=0,ans=0;
        int i;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i];
            if(sum==0)
            {
                ans=i+1;
            }
            if(m.find(sum)!=m.end())
            {
                int index = i-m[sum];
                ans=max(ans,index);
            }
            else
            {
                m[sum]=i;
            }
        }
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends

