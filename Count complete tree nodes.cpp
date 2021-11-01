/*
Problem Link: https://leetcode.com/problems/count-complete-tree-nodes/

Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and 
all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete.
*/


class Solution {
public:
    
    // Time complexity: O(log n * log n)
    int countNodes(TreeNode* root) {
        
        int lh = 0, rh = 0;
        TreeNode* curr = root;                     // O(h)
        while(curr != NULL){
            lh++;
            curr = curr->left;
        }
    
        curr = root;
        while(curr != NULL){                       // O(h)
            rh++;
            curr = curr->right;
        }
    
        if(lh == rh) return pow(2, lh) - 1;
        
        int cnt1 = countNodes(root->left);         // O(h) + O(log n* log n) is shared
        int cnt2 = countNodes(root->right);        // btw cnt1 && cnt2
    
    return cnt1 + 1 + cnt2;
    }
};


