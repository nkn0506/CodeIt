/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())    //do binary search on smaller length array
        {
            return findMedianSortedArrays(nums2,nums1);  //swap nums2 and nums1 if nums2 have smaller length
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0, h = n1;
        
        while(l<=h)
        {
            int cut1 = (l+h)/2; //midpoint for nums1 array
            int cut2 = (n1+n2+1)/2 - cut1;   //n1+n2+1/2 = half of the total numbe rof elements from both the arrays
            
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2==n2 ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;  //for even number of elements
                }
                else
                {
                    return max(l1,l2);   //for odd number of elements
                }
            }
            //binary search algo
            else if(l1>r2)
            {
                h = cut1-1;
            }
            else
            {
                l = cut1+1;
            }
        }
        return 0.0;
        
    }
};


