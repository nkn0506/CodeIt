/*
Given an array A of non-negative integers. Sort the array in ascending order such that element at the Kth position in unsorted array stays unmoved and all other elements are sorted. 

Example 1:

Input:
N = 5, K = 2
arr[] = {3 12 30 79 2}
Output: 2 12 3 30 79
Explanation: The element at the 2nd 
position (12) remains at its own place 
while others are sorted.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




class Solution
{
    public:
        void strangeSort (int arr[], int n, int k)
            {
            	//code here.
            	int temp = arr[k-1];
            	arr[k-1] = INT_MAX;
            	int i;
            	sort(arr,arr+n);
            	for(i=n-1;i>k-1;i--)
            	{
            	    arr[i]=arr[i-1];
            	}
            	arr[k-1]=temp;
            	
            }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
		int k; cin >> k;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
        Solution ob;
		ob.strangeSort (arr, n, k);
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
    }
}

// } Driver Code Ends

