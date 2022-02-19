/*
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the 
inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values. 
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
 */

class Solution {
public:
    
    TreeNode* solver(vector<int>& inorder, vector<int>& preorder, map<int, int>& mp, int& idx, int si, int ei){

        if(si > ei) return NULL;

        if(idx > preorder.size()-1) return NULL;
        int inorder_idx = mp[preorder[idx]]; 
        idx++; 

        TreeNode* curr = new TreeNode (inorder[inorder_idx]);
        curr->left = solver(inorder, preorder, mp, idx, si, inorder_idx-1);
        curr->right = solver(inorder, preorder, mp, idx, inorder_idx+1, ei);

    return curr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        
        int idx = 0;
        TreeNode* root = solver(inorder, preorder, mp, idx, 0, n-1);
    
    return root;
    }
};

