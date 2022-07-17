/*
You are given 2 numbers (n , m); the task is to find nvm (nth root of m).
 

Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.

Approach: Binary search
Time complexity: N*log(m*10^d)
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
        int l=1;
	    int h=m;
	    while(l<=h)
	    {
	        int mid=(l+h)/2;
	        if(pow(mid,n)==m)
	            return mid;
	        else if(pow(mid,n)>m)
	            h=mid-1;
	        else
	            l=mid+1;
	    }
	    return -1;	
	   
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends

