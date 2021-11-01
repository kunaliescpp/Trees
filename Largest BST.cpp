/*
Problem Link: https://practice.geeksforgeeks.org/problems/largest-bst/1

Largest BST 

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:
Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size 
equal to 1.

Example 2:
Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a BST of size 2: 
       2
    /    \ 
   N      8


Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6
*/


class Solution{
    public:
    
    class SubTreeInfo{
        
        public:
        int min, max;
        int size;
        bool isBST;
     
        SubTreeInfo(int min, int max, int size, bool isBST){
            this->min = min;
            this->max = max;
            this->size = size;
            this->isBST = isBST;
        }
    };
    
    SubTreeInfo* findLargestBST(Node *root){
        
        if (root == NULL) {
            return new SubTreeInfo(INT_MAX, INT_MIN, 0, true);
        }
        
        SubTreeInfo* ls = findLargestBST(root->left);
        SubTreeInfo* rs = findLargestBST(root->right);
        
        // Check if a Binary tree rooted under the current root is a BST
        // 1. Left and right subtree are also BST
        // 2. root node > largest value in the left subtree
        // 3. root node < smallest value in the right subtree
        
        SubTreeInfo* info = NULL;
        if (ls->isBST && rs->isBST && (root->data > ls->max && root->data < rs->min)){
            info = new SubTreeInfo(min({root->data, ls->min, rs->min}), max({root->data, ls->max, rs->max}), ls->size +1+ rs->size, true);
        } else {
            info = new SubTreeInfo(0, 0, max(ls->size, rs->size), false);
        }
        
    return info;
    }
    
    int largestBst(Node *root){
    
    return findLargestBST(root)->size;
    }
};


