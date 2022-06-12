/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]

Approach 1: By calculating number of nodes first and then traverse the linked list till c-n-1 and then delete required node
Time complexity: O(2N)

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int c=1;
        while(temp->next!=NULL)
        {
            c++;
            temp=temp->next;
        }
         if(n == c)
            return head->next;
        temp = head;
        int x = c-n-1;
        for(int i=1;i<=x;i++)
        {
            temp=temp->next;
        }
        if(temp->next ==NULL)
        {
            temp = NULL;
        }
        else
        {
            temp->next = temp->next->next;
        }
        return head;
        
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start,*slow,*fast;
        start = new ListNode();
        start->next = head;
        slow = start;
        fast = start;
        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
        
    }
};
