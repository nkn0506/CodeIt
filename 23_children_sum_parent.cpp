/*
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.

Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

 Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.
*/

#include<stdio.h>
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
    bool checkTree(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        int a,b;
        if(root->left==NULL)
        {
            a=0;
        }
        else
        {
            a=root->left->val;
        }
        if(root->right==NULL)
        {
            b=0;
        }
        else
        {
            b=root->right->val;
        }
        if(a+b!=root->val)
        {
            return false;
        }
        
        return checkTree(root->left) && checkTree(root->right);
        
    }
};


