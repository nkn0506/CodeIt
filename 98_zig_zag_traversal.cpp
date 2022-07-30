/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        bool flag = true;
        while(!q.empty())
        {
            int s = q.size();
            vector<int>arr(s);
            for(int i=0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                
                int index = flag ? i : (s-1-i);
                arr[index] = temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            //make flag 0 if 1 and i if 0
            //0 = left to right
            //1 = right to left
            flag = !flag;
            ans.push_back(arr);
        }
        
        return ans;
    }
};


