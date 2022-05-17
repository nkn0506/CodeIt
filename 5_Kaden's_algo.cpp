/*
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
Input:
N = 5
Arr[] = {1,2,3,-2,5}
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
    
        int i;
        int max=arr[0];
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>max)
            {
                max=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return max;
        
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

