#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

int find_ans(int arr[],int n)
    {
    	int i;
    	int max_ = 0;
    vector<int>right(n,0);
    for(i=n-1;i>=0;i--)
    {
    	if(i==n-1)
    	{
    		right[i]=arr[i];
		}
    	right[i] = max(arr[i],right[i+1]);
	}
    	set<int> s;
    	s.insert(arr[0]);
    	for(i=1;i<n;i++)
    	{
    		s.insert(arr[i]);
    		auto it = s.find(arr[i]); //find arr[i] in set
    		if(it!=s.begin && right[i]!=arr[i])
    		{
    			max_ = max(max_,(*--it+arr[i]+right[i]));
			}
		}
	}
int main()
{
    int arr[] = { 2, 5, 3, 1, 4, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << find_ans(arr, n);
    return 0;
}

