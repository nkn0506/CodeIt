/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"

Using brute force by recursion: Time complexity: O(N!)+O(N)+O(logN).....too long
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int i;
        int fact = 1;
        vector<int> num;
        //compute factorial till n-1 number
        for(i=1;i<n;i++)
        {
            fact = fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        //as 0 indexed so k=k-1;
        k=k-1;
        string ans = "";
        while(true)
        {
            int x = k/fact;
            //means permutation for 1st x numbers is done
            //eg., x = 2, then permutation for 1 and 2 is done next is 3
            //so put num[x] in answer
            ans = ans+to_string(num[x]);
            //delete that element from num array
            num.erase(num.begin()+x);
            if(num.size()==0)
            {
                break;
            }
            //reduce k and fact as num.size() get reduced
            k = k%fact;
            fact = fact/num.size();
        }
        
        return ans;   
    }
};
int main()
{
	Solution s;
	cout<<s.getPermutation(4,17);
	return 0;
}

