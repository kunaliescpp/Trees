/*
Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the 
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode *lc =  lowestCommonAncestor(root->left, p, q);
        TreeNode *rc =  lowestCommonAncestor(root->right, p, q); 
         
        if(lc && rc) return root;
        else if(!lc && rc) return rc;
        else if(lc && !rc) return lc;
        else return NULL;
    }
};

/*
        EFFICIENT SOLUTION:

        if(root == NULL) return NULL;
        
        if(root->val > p->val && root->val > q->val){
            TreeNode *a =  lowestCommonAncestor(root->left, p, q);
            return a;
        }
        
        else if(root->val < p->val && root->val < q->val){
            TreeNode *b =  lowestCommonAncestor(root->right, p, q); 
            return b;
        }
        
        else return root;
*/        

