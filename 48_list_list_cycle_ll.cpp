/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Approach 1: Time complexity: O(N), space complexity: O(N)
//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head) {
//          ListNode * p = head;
//         vector<ListNode *>v;
//         ListNode* ans = NULL;
//         while(true)
//         {
            
//             if(p==NULL)
//             {
//                 ans = NULL;
//                 break;
//             }
//             else if(p->next==NULL)
//             {
//                 ans = NULL;
//                 break;
//             }
//             else
//             {
//                 if(find(v.begin(),v.end(),p)!=v.end())
//                 {
//                     ans = p;
//                     break;
//                 }
//                 v.push_back(p);
//             }
//             p=p->next;
//         }
//         return ans;    
//    }
//};

Approach 2: Using floyd's tortoise and hare algorithm, Time complexity: O(N), space complexity: O(1)
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
        {
            return NULL;
        }
        ListNode* slow,*fast;
        slow = head;
        fast = head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                fast=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return NULL;
        
    }
};

