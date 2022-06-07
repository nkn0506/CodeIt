/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long merge(long long a[],long long l,long long m,long long r,long long temp[])
    {
        
        long long c = 0; 
        int i=l,j=m+1; int k = l; 
        
        while(i<=m and j<=r){
            if(a[i] <= a[j]){
                temp[k++] = a[i++];
            }else{
                temp[k++] = a[j++];
                c += (m+1)-i;
            }
        }
        
        while(i<=m){
            temp[k++] = a[i++];
        }
         while(j<=r){
            temp[k++] = a[j++];
        }
        
        for(int i=l;i<=r;i++)
            a[i] = temp[i];
        
        return c;
      
        
    }
    long long int mergesort(long long arr[],long long l,long long h,long long temp[])
    {
        long long int ans = 0;
        if(l<h)
        {
            long long mid = (l+h)/2;
            ans=ans+mergesort(arr,l,mid,temp);
            ans=ans+mergesort(arr,mid+1,h,temp);
            ans=ans+merge(arr,l,mid,h,temp);
        }
        return ans;
        
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        // ordered_set s;
        // long long c = 0;
        // for(int i=n-1;i>=0;i--)
        // {
        //     c = c+s.order_of_key(arr[i]);
        //     s.insert(arr[i]);
        // }
        // return c;
        long long temp[n];
        return mergesort(arr,0,n-1,temp);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends

