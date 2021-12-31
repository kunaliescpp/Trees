/*
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is 
the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/
class Solution {
public:
    TreeNode* solver(vector<int>& inOrder, vector<int>& postOrder, int& idx, int si, int ei){

        if(si > ei) return NULL;

        int inOrder_idx = -1;
        for(int i = si; i <= ei; i++){
            if(inOrder[i] == postOrder[idx]){
                inOrder_idx = i; 
                idx--; break;
            } 
        }

        TreeNode* curr = new TreeNode (inOrder[inOrder_idx]);
        curr->right = solver(inOrder, postOrder, idx, inOrder_idx+1, ei);
        curr->left = solver(inOrder, postOrder, idx, si, inOrder_idx-1);

    return curr;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    
        int n = inorder.size(), m = postorder.size();
        int idx = m-1;
        TreeNode* root = solver(inorder, postorder, idx, 0, n-1);

    return root;
    }
};


