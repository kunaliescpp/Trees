/*
Problem Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Boundary Traversal of binary tree 

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you
always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node 
you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it 
was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:
Input:
        1
      /   \
     2     3    
   
Output: 1 2 3

Example 2:
Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22
*/


class Solution {
    public:
   //Time complexity : O(n)
   //Space complexity : O(n)
    void leftBoundary(Node* root, vector<int>& v){

        //leaves has seperate function so, return if leaves occur
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    
        v.push_back(root->data);
        
        if(root->left != NULL) leftBoundary(root->left, v);
        else leftBoundary(root->right, v);
    }

    void rightBoundary(Node* root, vector<int>& v){
        
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        if(root->right != NULL) rightBoundary(root -> right, v);
        else rightBoundary(root -> left, v);
        
        v.push_back(root->data);
    }

    void leafNodes(Node* root, vector<int>& v){
        
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->data);
            return;
        }
        
        leafNodes(root->left, v);
        leafNodes(root->right, v);
    }

    vector <int> printBoundary(Node *root){
        
        vector<int> v;
        
        if(root == NULL) return v;
        
        v.push_back(root->data);
        
        leftBoundary(root->left, v);
        
        leafNodes(root->left, v);
        leafNodes(root->right, v);
        
        rightBoundary(root->right, v);
    return v;
    }
};

  
