/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 

Time complexity: O(NlogN)+O(N)
Space complexity: O(1)
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool cmp(Item a, Item b)
{
    double p = (double)a.value/(double)a.weight;
    double q = (double)b.value/(double)b.weight;
    return p>q;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        
        int curwt = 0;
        double final_val = 0;
        int i;
        for(i=0;i<n;i++)
        {
            if(curwt+arr[i].weight<=w)
            {
                curwt = curwt+arr[i].weight;
                final_val = final_val+arr[i].value;
            }
            else
            {
                int remain = w-curwt;
                final_val = final_val+((double)arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return final_val;
    }
        
};
// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends

