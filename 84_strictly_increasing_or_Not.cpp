/*
Given an array arr[] of positive integers, the task is to find whether it is possible to make this array strictly increasing by modifying atmost one element.
Examples: 
 

Input: arr[] = {2, 4, 8, 6, 9, 12} 
Output: Yes 
By modifying 8 to 5, array will become strictly increasing. 
i.e. {2, 4, 5, 6, 9, 12}
Input: arr[] = {10, 5, 2} 
Output: No 

Time complexity: O(N)
Space complexity: O(1)
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
bool find_ans(int arr[],int n)
{
	int c = 0;
	//for 1st element 
	if(arr[0]>arr[1])
	{
		c++;
		arr[0] = arr[1]/2;
	}
	
	//check from 2nd to 2nd last number
	int i;
	for(i=1;i<n-1;i++)
	{
		if(arr[i-1]<arr[i] && arr[i+1]<arr[i] || arr[i-1]>arr[i] && arr[i+1]>arr[i])
		{
			arr[i] = (arr[i-1]+arr[i+1])/2;
			c++;
		}
	}
	
	//check for last element
	if(arr[n-1]<arr[n-2])
	{
		c++;
	}
	if(c>1)
	{
		return false;
	}
	return true;
}
int main()
{
    int arr[] = { 2, 4, 8, 6, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (find_ans(arr, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;
}

