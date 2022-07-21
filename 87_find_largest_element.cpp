/*
Given an integer N the task is to find the largest number which is smaller or equal to it and has its digits in non-decreasing order.

Examples 1:

Input:
N = 200
Output:
199
*/

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool find_ans(string s)
    {
        int i;
        for(i=1;i<s.length();i++)
        {
            if(s[i]<s[i-1])
            {
                return false;
            }
        }
        return true;
    }
    int find(int N){
        // code here
        
        int i;
        for(i=N;i>0;i--)
        {
            if(find_ans(to_string(i)))
            {
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends

