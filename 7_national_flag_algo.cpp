/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Solution-->
1) sorting using sort() function = by using sorting technique the time complexity would be O(NlogN)
sort(nums.begin(),nums.end()
2) To optimize this we can do it by count the no's of 0,1 and 2 = time complexity would be O(N)+O(N)=O(2N)
class Solution {
    public void sortColors(int[] nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int val : nums){
            if(val == 0){
                zero++;
            } else if(val == 1){
                one++;
            } else{
                //val == 2
                two++;
            }
        }
        int i = 0;
        while(zero-- > 0){
            nums[i++] = 0;
        }
        while(one-- > 0){
            nums[i++] = 1;
        }
        while(two-- > 0){
            nums[i++] = 2;
        }
    }
}
3) using dutch national flag algorithm = O(N)  
*/
 
 

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[mid],nums[low]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;        
            }
        }
        
    }
};
int main()
{
	Solution s;
	vector<int>v({2,0,2,1,1,0});
	s.sortColors(num);
	cout<<"Array after sort: "<<endl;
    for(int i=0;i<num.size();i++)
    {
    	cout<<"  "<<num[i];
	}

	return 0;
}

