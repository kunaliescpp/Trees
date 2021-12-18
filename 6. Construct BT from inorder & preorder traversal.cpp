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
// Approach: preorder vector me iterate karna he and tree ko inorder arrangement ke according arrange karna he
    int preIndex = 0;
    TreeNode* cTree(vector<int>& preorder, vector<int>& inorder, int is, int ie){   //inorder start
                                                                                    //inorder end
        if(is > ie) return NULL;
        TreeNode *root = new TreeNode (preorder[preIndex++]);
        
        int inIndex;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == root->val){
                inIndex = i;
                break;
            }
        }
    
       root->left = cTree(preorder, inorder, is, inIndex-1);
       root->right = cTree(preorder, inorder, inIndex + 1, ie);
    
    return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
       TreeNode* curr = cTree(preorder, inorder, 0, inorder.size()-1);
        
    return curr;
    }
};

