/*
Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Constraints:
The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


class Solution {
public:
    // Time complexity : O(2*n)        
    // space complexity : O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>v;
        if(root == NULL) return {};
        
        stack<TreeNode *>stk;
        TreeNode *curr = root;
        TreeNode *prv = NULL;
        
        while( curr != NULL || !stk.empty()){
            
           while(curr != NULL){
               stk.push(curr);
               curr = curr->left;
           }
       
            curr = stk.top();
            if(curr->right == NULL || curr->right == prv){
                v.push_back(curr->val);
                stk.pop();
                prv = curr;
                curr = NULL;
            } else{
                curr = curr->right;
            }
        } 
    return v;
    }
};


