/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
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

//-1 = self unchecked so please check it
//1 = alread checked so don't check its parent

class Solution {
public:
    int count = 0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==-1)
        {
            count++;
        }
        
        return count;  
    }
    int dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l==-1 || r==-1)
        {
            count++;
            return 1; 
        }
        else if(l==1 || r==1)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
};

