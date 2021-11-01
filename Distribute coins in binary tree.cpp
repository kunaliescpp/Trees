/*
Problem Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/

Distribute Coins in Binary Tree

You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins 
in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to 
child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

Example 1:
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from
the root of the tree to the right child.

Example 3:
Input: root = [1,0,2]
Output: 2

Example 4:
Input: root = [1,0,0,null,3]
Output: 4
 
 
Constraints:
The number of nodes in the tree is n.
1 <= n <= 100
0 <= Node.val <= n
The sum of all Node.val is n.
 */

class Solution {
public:
// it is a classic family story namely,preorder.
//if child has no coins -> child says parent mujhe 1 move me coin do by returning -1 (abs(-1) move me vapis lega);
//if child has 3 coins -> child says 2 tum rakhlo by returning 2 (2 moves me dega)
    int coins(TreeNode* root, int& moves){
        
        if(root == NULL) return 0;
        
        int l = coins(root->left, moves);
        int r = coins(root->right, moves);
        
        moves += abs(l) + abs(r);
        
    return (l + r + root->val - 1);                 //return -1 if(no children && no coin) 
    }
    
    int distributeCoins(TreeNode* root) {
        
        int moves = 0;
        coins(root, moves);
    
    return moves;
    }
};



