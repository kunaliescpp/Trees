/*
Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,null,null,9,6,null,null,7]
Output: 8
Explanation: The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int maxi = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            
            int f = q.front().second;              
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front().first;
                int val = q.front().second;
                q.pop();
                
                if(i == n-1) maxi = max(maxi, val-f+1);
                
                if(node->left != NULL) q.push({node->left, 2*(val-f)+1});                    // overflow in, int c1 =  2*curr_idx + 1
                if(node->right != NULL) q.push({node->right, 2*(val-f)+2});
            }
        }
    
    return maxi;
    }
};


