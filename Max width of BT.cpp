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
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            
            int min_idx = q.front().second;              //to make id starting from 0
            int sn, en;
            int k = q.size();
            while(k--){
                TreeNode* f = q.front().first;
                int curr_id = q.front().second - min_idx;
                q.pop();
                
                if(k == q.size()-1) sn = curr_id;
                if(k == 0) en = curr_id;
                
                if(f->left != NULL) q.push({f->left, 2*curr_id+1});                    // overflow in, int c1 =  2*curr_idx + 1
                if(f->right != NULL) q.push({f->right, 2*curr_id+2});
            }
        
        ans = max(ans, en-sn+1);
        }
    
    return ans;
    }
};


