/*
Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [1,2]
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

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
    
    //Time complexity: O(nodes), all nodes push & pop in stack at O(1)
    //Space complexity: O(h)
    
    // Inorder(leftSubtree    root    rightSubtree)
    vector<int> inorderTraversal(TreeNode* root) {                         
        
         vector<int>v;
        if(root == NULL) return {};
        
        stack<TreeNode *>stk;
        // stk.push(root);
        TreeNode *curr = root;
        
        while( curr != NULL || !stk.empty()){
            
           while(curr != NULL){
               stk.push(curr);
               curr = curr->left;
           }
        
            curr = stk.top();
            stk.pop();
            v.push_back(curr->val);
            curr = curr->right;
        } 
    return v;
    }
};


