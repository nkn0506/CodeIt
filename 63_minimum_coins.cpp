/*
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?

Examples:  

Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

time complexity: O(V)
space complexity:O(V)
*/
#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int v;
    cin>>v;
    int arr[]={1,2,5,10,20,50,100,500,1000};
    int n = 9;
    int i;
    vector<int>ans;
    for(i=n-1;i>0;i--)
    {
        while(v>=arr[i])
        {
            v=v-arr[i];
            ans.push_back(arr[i]);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<endl;
    }

    return 0;
}

