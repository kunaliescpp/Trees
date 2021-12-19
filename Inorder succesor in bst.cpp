/*
Problem Link: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

Inorder Successor in BST 

Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
 
Example 1:
Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3 
Explanation: Inorder traversal : 1 2 3 .Hence, inorder successor of 2 is 3.

Example 2:
Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
K(data of x) = 8
Output: 10
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, successor of 8 is 10.
 
 
Constraints:
1 <= N <= 1000, where N is number of nodes
*/


class Solution{
  public:
    
    void solver(Node* root, Node *x, Node*& next){
        
        if(root == NULL) return;
        
        if(root->data > x->data){
            next = root;
            solver(root->left, x, next);
        } else {
            solver(root->right, x, next);
        }
    }
    
    Node *inOrderSuccessor(Node *root, Node *x){
      
      Node *next = NULL;
      solver(root, x, next);

    return next;
    }
};


