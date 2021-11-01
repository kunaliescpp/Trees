/* 
Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:
The number of nodes in the tree is in the range [1, 3 * 10^4].
-1000 <= Node.val <= 1000
 */


class Solution {
public:

    int solver(TreeNode* root, int& maxSum){
      
       //base case 
       if(root == NULL) return 0;
       
       //recursive calls
        int l = solver(root->left, maxSum);
        int r = solver(root->right, maxSum);
        
        int temp = max({root->val, l + root->val, r + root->val});
        maxSum = max({maxSum, temp, l+r+root->val});
        
    return temp;         //input = [-3], output = 0
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxSum = -1e9;
        solver(root, maxSum);
    return maxSum;
    }
};





