/*
Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
 

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

class Solution {
public:
    // Time complexity : O(n)                      //queue & deque for n nodes
    // Space comlexity : O(n)                      // width of tree
    vector<vector<int>> levelOrder(TreeNode* root) {
       
         vector<vector<int>> bv;
        if(root == NULL) return {};
        queue<TreeNode *>q;
        q.push(root);
        
        while(! q.empty()){
            
            int k = q.size();
            vector<int>sv;
            
            while(k--){
               TreeNode *curr = q.front();
               q.pop();
               sv.push_back(curr->val);
            
               if(curr->left != NULL) q.push(curr->left);
               if(curr->right != NULL) q.push(curr->right);
            }    
           bv.push_back(sv);   
        }
        
    return bv;
    }
};


