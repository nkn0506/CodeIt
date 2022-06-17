/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]

Approach 1: Traversing the linked list till pointer reaches 2nd last node, then make it's next as NULL and make its next as head and put that node in head;
            Time complexity: O(K*N)
            Space complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy = NULL;
        while(k)
        {
            ListNode* temp = head;
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            dummy = temp->next;
            temp->next = NULL;
            dummy->next = head;
            head = dummy;
            k--;
        }
        return head;
        
    }
};

Approach 2: Time complexity: O(N*K%N)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy = NULL;
        ListNode *ptr = head;
        int count = 0;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            count++;
        }
        while(k%count)
        {
            ListNode* temp = head;
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            dummy = temp->next;
            temp->next = NULL;
            dummy->next = head;
            head = dummy;
            k--;
        }
        return head;
        
    }
};

Approach 3:

*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        //count total number of nodes;
        //make linking between last node and head node
        
        ListNode *ptr = head;
        int count = 1;
        while(ptr->next!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        
        ptr->next = head;
        k = k % count;
        k = count - k;
        
        while(k--)
        {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;    
    }
};

