/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Approach 1: Naive approach: Bystoring elements in string or vector array and then check whether palindrome or not
Time complexity: O(N), space complexity: O(N)
-->
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string str;
        if(head->next == NULL){
            return true;
        }
        while(head)
        {
            str.push_back(head->val);
            head = head->next;
        }
        string x = str;
        reverse(str.begin(),str.end());
        if(x==str)
        {
            return true;
        }
        return false;
        
    }
};

Approach 2: Space complxity: O(1)......By reversing half of the linked after calculating middle of the linked list
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
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
    ListNode * reverse_list(ListNode *head)
    {
        ListNode* prev, *next;
        prev = next =NULL;
        while(head!=NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // string str;
        if(head->next == NULL){
            return true;
        }
        
        ListNode* slow, *fast;
        slow=fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next = reverse_list(slow->next);
        
        slow=slow->next;
        while(slow!=NULL)
        {
            if(slow->val!=head->val)
            {
                return false;
            }
            slow=slow->next;
            head = head->next;
            
        }
        return true;   
    }
};

