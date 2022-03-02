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

// reverse preorder approach
void flatten_nodes(TreeNode* root, TreeNode *&nxt){
  if(root == NULL) return;

  flatten_nodes(root->right, nxt);
  flatten_nodes(root->left, nxt);

  if(nxt == NULL){
      // curr->left = NULL;
      // curr->right = NULL;
      nxt = root;
  } else{
      root->left = NULL;
      root->right = nxt;
      nxt = root;
  }
}

void flatten(TreeNode* root) {
  TreeNode *nxt = NULL;
  flatten_nodes(root, nxt);  
}


