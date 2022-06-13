/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        ListNode *p,*q;
        p = l1;
        q = l2;
        int carry=0;
        while(p!=NULL || q!=NULL)
        {
            int x,y;
            if(p!=NULL)
            {
                x = p->val;
            }
            else
            {
                x = 0;
            }
            if(q!=NULL)
            {
                y = q->val;
            }
            else
            {
                y = 0;
            }
            
            int sum = carry+x+y;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            
            temp=temp->next;
            if(p!=NULL)
            {
                p=p->next;
            }
            if(q!=NULL)
            {
                q=q->next;
            }
            
        }
        if(carry>0)
        {
            temp->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

