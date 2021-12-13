/*
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is 
the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

Node* solver(int inorder[], int postorder[], int& pi, int si, int ei){

    if(si > ei) return NULL;

    Node *root = new Node (postorder[pi]);
    pi--;

    int idx;
    for(int i = si; i <= ei; i++){
        if(inorder[i] == root->val){
            idx = i; break;
        }
    }

    root->right = solver(inorder, postorder, pi, idx + 1, ei);
    root->left = solver(inorder, postorder, pi, si, idx-1);
 
return root;
}

Node* construct(int inorder[], int postorder[]){

    int n = postorder.size();

    Node *root = solver(inorder, postorder, n-1, 0, n-1);

return root;
}


