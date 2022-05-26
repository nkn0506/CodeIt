/*
We are given two sorted arrays. 
We need to merge these two arrays such that the initial numbers 
(after complete sorting) are in the first array and the remaining numbers are in the second array. Extra space allowed in O(1).

Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}  

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}
        
Approach1:  As the arrays are already sorted we can't replace direclty from the begin. 
Hence we have to swap the jth element of arr2 with the kth element where 'k' starts from n-1 upto i
Time complexity: O(N+M) in worst case and for sorting the two arrays is O(Nlog(N)+Mlog(M))
Space complexity: O(1)
*/

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=0,j=0,k=n-1;
            while(i<=k && j<m)
            {
                if(arr1[i]<arr2[j])
                {
                    i++;
                }
                else
                {
                    swap(arr1[k],arr2[j]);
                    j++;
                    k--;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends

