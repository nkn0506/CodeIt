/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Input: 3->2->0->4->2
Output: True

Solution 1:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * p = head;
        vector<ListNode *>v;
        bool ans = false;
        while(true)
        {
            
            if(p==NULL)
            {
                ans = false;
                break;
            }
            else if(p->next==NULL)
            {
                ans = false;
                break;
            }
            else
            {
                if(find(v.begin(),v.end(),p)!=v.end())
                {
                    ans = true;
                    break;
                }
                v.push_back(p);
            }
            p=p->next;
        }
        return ans;  
    }
};
Solution 2: One of which is to have a hash or set, keeping track of every node seen. If a node has already been seen, then you know it's a cycle.
Solution 3: We can optimize this using Floyd's tortoise and hare algorithm(using fast and slow algorithm --(space complexity - O(1) and time complexity - O(N)
            Phase 1: detect cycle
            Phase 2: find entry point
*/
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
    bool hasCycle(ListNode *head) {

        
        // solution 2:
        
        
        ListNode *slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
        
        
    }
};

