/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Approach 1: Using external space to store new merge sorted linked list using two pointers at list1 and list2
Time complexity: O(N1)+O(N2)
spach complexity: O(N1+N2)
solution:

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy,*temp;
        dummy = new ListNode();
        temp = dummy;
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                list1=list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp=temp->next;
        }
        
        
        if(list1)
        {
            temp->next = list1;
        }
        if(list2)
        {
            temp->next = list2;
        }
        return dummy->next;
        
    }
};

Approach 2:
*/
Using O(1) space complexity and O(n1+n2)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
         if(list1==NULL)
         {
             return list2;
         }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val  > list2->val)
        {
            swap(list1,list2);
        }
        ListNode *ans = list1;
        while(list1!=NULL && list2!=NULL)
        {
            ListNode *temp = NULL;
            while(list1!=NULL && list1->val<=list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1,list2);
        }
        return ans;
        
    }
};

