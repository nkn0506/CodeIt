/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool find_ans(TreeNode* lnode,TreeNode* rnode)
    {
        if(lnode==NULL && rnode==NULL)
        {
            return true;
        }
        if((lnode==NULL && rnode!=NULL) || (lnode!=NULL && rnode==NULL))
        {
            return false;
        }
        return (lnode->val==rnode->val)&&find_ans(lnode->left,rnode->right)&&find_ans(lnode->right,rnode->left);
    }
    bool isSymmetric(TreeNode* root) {
        return find_ans(root->left,root->right);    
    }
};
//int main()
//{
//
//
//	return 0;
//}

