/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

 Approach 1: Brute force, Time complexity: O(N*M)
 Approach 2: Using hashmap or hashset, Time complexity: O(N+M), space complexity: O(N)
        unordered_set<ListNode *> set;
        while (headA != NULL) 
		{
            set.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL) {
            if (set.find(headB) != set.end()) return headB;
            headB = headB->next;
        }
        return NULL;
Approach 3: Time complexity: O(2M), Space complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        ListNode *p,*q;
        p = heada;
        q = headb;
        int c1=0,c2=0;
        while(p->next!=NULL)
        {
            c1++;
            p=p->next;
        }
        while(q->next!=NULL)
        {
            c2++;
            q=q->next;
        }
        p=heada;
        q=headb;
        
        int gap = abs(c1-c2);
        if(c1>c2)
        {
            while(gap>0)
            {
                p=p->next;
                gap--;
            }
            
        }
        else if(c1<c2)
        {
            while(gap>0)
            {
                q=q->next;
                gap--;
            }
        }
        while(p!=q)
        {
            p=p->next;
            q=q->next;
        }
        return p;
    }
};

Approach 4: take 2 dummy nodes and move them until they are equal
Time complexity: O(2M)
-->
*/
 

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        
        ListNode *p,*q;
        p=heada;
        q=headb;
        while(p!=q)
        {
            p = p==NULL?headb:p->next;
            q = q==NULL?heada:q->next;
        }
        return p;
    }
};

