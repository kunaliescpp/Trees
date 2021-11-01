/*
Problem Link: https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

Recover BST

You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) 
the BST by swapping them back. Do not change the structure of the tree.

Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be 
reflected in the original linked list.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation: By swapping nodes 20 and 8, the BST can be fixed.
 
Example 2:
Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: By swapping nodes 11 and 10, the BST can be fixed.

Constraints:
1 ≤ Number of nodes ≤ 10^3
*/

class Solution {
  public:
 
  void correction(Node *root, Node *&prv, Node *&incorrect1, Node *&incorrect2){

      if(root == NULL) return;

      // inorder
      correction(root->left, prv, incorrect1, incorrect2);

      if(prv != NULL && root->data < prv->data){
          if(incorrect1 == NULL) incorrect1 = prv;

          incorrect2 = root;
      }

      prv = root;
      correction(root->right, prv, incorrect1, incorrect2);
  }
  
  void correctBST(struct Node* root){

      Node *prv = NULL, *incorrect1 = NULL, *incorrect2 = NULL;
      correction(root, prv, incorrect1, incorrect2);

      swap(incorrect1->data, incorrect2->data);
      swap(incorrect1, incorrect2);
  }
};


