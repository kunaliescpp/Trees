/*
Problem Link: https://leetcode.com/problems/binary-tree-pruning/

Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
A subtree of a node node is node plus every node that is a descendant of node.

Example 1:
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]

Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
 

Constraints:
The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.
 */

class Solution {
public:
    
    bool solver(TreeNode*& root){
        
        if(root == NULL) return false;
        
        bool a = solver(root->left);
        bool b = solver(root->right);
        
        if(a == false && b == false && root->val == 0){
            root = NULL;
            return false;
        } else{
            return true;
        }
        
    return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL) return NULL;
    
        solver(root);
        
    return root; 
    }
};


