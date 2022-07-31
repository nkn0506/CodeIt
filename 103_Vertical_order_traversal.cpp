/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;   // (root,0,0) or (root->left,-1,1)
        map<int,map<int,vector<int>>>m;
        q.push(make_pair(root,make_pair(0,0)));
        
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                pair<TreeNode*,pair<int,int>> tem = q.front();
                
                q.pop();
                TreeNode* temp = tem.first;
                int index = tem.second.first;
                int level = tem.second.second;
                
                m[index][level].push_back(temp->val);
                if(temp->left)
                {
                    q.push(make_pair(temp->left,make_pair(index-1,level+1)));
                }
                if(temp->right)
                {
                    q.push(make_pair(temp->right,make_pair(index+1,level+1)));
                }
            }
        }
        
        for(auto it: m)  // 0: (2: 10,9)    =   0(index): (2(level): 10,9)
        {
            vector<int>arr;
            for(auto j: it.second)      //j.first = 0 and j.second = (2: 10,9)
            {
                sort(j.second.begin(),j.second.end());
                for(auto x: j.second)
                {
                    arr.push_back(x);
                }
            }
            ans.push_back(arr);   
        }
       return ans;  
    }

};


