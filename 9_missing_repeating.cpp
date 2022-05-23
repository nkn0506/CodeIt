/*Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2

Solution-->

Approach 1: Using hashmap, store the frequency of the each element and then check which element occurs twice and which element has frequency 0.
Time complexity: O(2N)

Approach 2: Make two equations using sum and sum of squares.
Time complexity: O(N)
-->
long long int len = arr.size();
long long int sum = (length*(length+1))/2;
long long int sum_sq = (length*(length+1)*(2*length+1))/6;
//remove element one by one from sum ans sum_sq
for(i=0;i<len;i++)
{
    sum = sum - (long long int)arr[i];
    sum_sq = sum_sq - (long long int)arr[i] * (long long int)arr[i];
}
//let x = repeating number, y = missing number 
//x - y = sum, x^2 - y^2 = sum_sq
//by solving equations, we get
missing number = (sum + sum_sq/sum)/2;
repeating number = missing number - sum;
Approach 3: Using xor

*/

#include <bits/stdc++.h>

using namespace std;
// { Driver Code Starts



class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans;
        ans=new int(2);
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
        	if(m.find(arr[i])==m.end())
        	{
        		m[arr[i]]=1;
			}
			else
			{
				ans[0]=arr[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(m.find(i)==m.end())
			{
				ans[1]=i;
			}
		}
		return ans;
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        int *ans;
        ans=new int(2);
        ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends


