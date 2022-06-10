/*
to find xor from 1 to n: 
1.divide n with 4
2.rem==0, ans=n
3.rem==1, ans=1
4.rem==2, ans=n+1;
5.rem==3, ans=0

x^y = z;
y^z = x;
x^z = y
*/

/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
              
Approach 1: Brute force, time complexity: O(N^2)
#include <bits/stdc++.h>
using namespace std;
long long subarrayXor(int arr[], int n, int m)
{
	int i,j;
	long long count=0;
	for (int i = 0; i < n; i++) {
        int xor_ = 0;
 
        
        for (int j = i; j < n; j++) {
            xor_ = xor_ ^ arr[j];
 
            
            if (xor_ == m)
                count++;
        }
    }
	return count;
}

Approach 2: 
Using hashmap , Time complexity: O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;


long long subarrayXor(int arr[], int n, int mp)
{
     unordered_map<int, int> m;	
	 long long c=0;
	int *ans = new int[n];
	ans[0]=arr[0];
	int i,j;
	for(i=1;i<n;i++)
	{
		ans[i]=ans[i]^ans[i-1];
	}
	for(i=0;i<n;i++)
	{
		int temp = mp^ans[i];
		c=c+((long long)m[temp]);
		if(ans[i]==mp)
		{
			c++;
		}
		m[ans[i]]++;
	}
	return c;
}

// Driver program to test above function
int main()
{
	int arr[] = { 4, 2, 2, 6, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 6;

	cout << "Number of subarrays having given XOR is "
		<< subarrayXor(arr, n, m);
	return 0;
}





