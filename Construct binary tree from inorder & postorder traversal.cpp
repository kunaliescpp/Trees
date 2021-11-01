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


class Solution {
public:
// Approach: preorder vector me iterate karna he and tree ko inorder arrangement ke according arrange karna he
    
    TreeNode* cTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int is, int ie){//inorder st
                                                                                                 //inorder end
        if(is > ie) return NULL;
        TreeNode *root = new TreeNode (postorder[postIndex--]);
        
        int inIndex;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == root->val){
                inIndex = i;
                break;
            }
        }
    
    // As postOrder is (l r root ) so we traverse, l <- r <- root
       root->right = cTree(inorder, postorder, postIndex, inIndex + 1, ie);    // if(index+1 > ie) return NULL
       root->left = cTree(inorder, postorder, postIndex, is, inIndex - 1);     // if(is > inIndex-1)return NULL
    
    return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        
        int postIndex = postorder.size()-1;
       TreeNode* first = cTree(inorder, postorder, postIndex, 0, inorder.size()-1);
                      //cTree(inorder vec, postorder vec, postIndex, inorder start, inorder end)
    return first;
    }
};

// postorder tree input:

//         7
//        / \
//      20   15
//     /       \
//    3         9



