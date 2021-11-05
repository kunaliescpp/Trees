/*
Problem link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Flatten binary tree to linked list 

Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and 
the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:
      1               1
    /   \              \
   2     5       =>     2
  / \     \              \
 3   4     6              3
                           \
                            4
                             \           
                              5
                               \
                                6
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]


Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

class Solution {
public:
    
    //Approach: 5 ko 4 se link krenge   
    void flatten_nodes(TreeNode* curr, TreeNode *&prv){
        
        if(curr == NULL) return;
        
        flatten_nodes(curr->right, prv);
        flatten_nodes(curr->left, prv);
        
        curr->right = prv;
        curr->left = NULL;
        
        prv = curr;
    }
    
    void flatten(TreeNode* root) {
        
        TreeNode *prv = NULL;
        flatten_nodes(root, prv);  
    }
};


