/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.

Example 1:
Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int flag = 0;
            while(flag < size) 
            {
               TreeNode* node = q.front();
               q.pop();
               if(flag == 0){
                   ans = node->val;
               } 
               if(node->left){
                   q.push(node->left);
               } 
               if(node->right){
                   q.push(node->right);
               } 
               flag++;
            }            
        }
        return ans;

        
    }
};


