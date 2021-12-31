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
    TreeNode* solver(vector<int>& inOrder, vector<int>& preOrder, int& idx, int si, int ei){

        if(si > ei) return NULL;

        int inOrder_idx = -1;
        for(int i = si; i <= ei; i++){
            if(inOrder[i] == preOrder[idx]){
                inOrder_idx = i; 
                idx++; break;
            } 
        }

        TreeNode* curr = new TreeNode (inOrder[inOrder_idx]);
        curr->left = solver(inOrder, preOrder, idx, si, inOrder_idx-1);
        curr->right = solver(inOrder, preOrder, idx, inOrder_idx+1, ei);

    return curr;
    }

    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size(), m = preorder.size();
        int idx = 0;
        TreeNode* root = solver(inorder, preorder, idx, 0, n-1);
    
    return root;
    }
};

