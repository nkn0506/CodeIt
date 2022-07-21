/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
       if(n==1)
       {
           return 0;
       }
       if(n==2)
       {
           return arr[0]+arr[1];
       }
       
       priority_queue<long long, vector<long long>, greater<long long >> p;
       int i;
       for(i=0;i<n;i++)
       {
           p.push(arr[i]);
       }
       long long a,b;
       long long ans = 0;
       while(p.size()!=1)
       {
           a=0;
           b=0;
           a = p.top();
           p.pop();
           b = p.top();
           p.pop();
           ans = ans+a+b;
           p.push(a+b);
       }
       return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

