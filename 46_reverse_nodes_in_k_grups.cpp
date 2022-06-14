/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Time complexity: O(N)
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
    ListNode* find_ans(ListNode* head,int k,int length)
    {
        if(length<k)
        {
            return head;
        }
        
        ListNode* prev = NULL, *curr = head,*next = NULL;
        int count = 0;
        while(curr!=NULL && count<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL)
        {
            head->next = find_ans(next,k,length-k);
        }
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int length = 0;
        while(temp!=NULL)
        {
            length++;
            temp = temp->next;
        }
        return find_ans(head,k,length);
        
    }
};

