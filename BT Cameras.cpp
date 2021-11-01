/*
Problem Link: https://leetcode.com/problems/binary-tree-cameras/

Binary Tree Cameras

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor 
its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid 
configurations of camera placement.
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
 */


class Solution {
public:
//    once upon a time when all tree nodes are active, its Every Node's Story:
//         1. mere pass Camera he : 0
//         2. mere pass Camera nhi he : -> nhi chahiye mujhse niche vale node pe he : 1
//                                      -> camera ki need he upar vale pe hona chahiye : -1
    
// Approach: leaf node ko camera nhi denge, parent node ko denge jisse leaf and grandparent dono cover honge 
// this condition should carefully examine: node ke left pe he bas 1 node (without camera) or right pe camera  he to parent node
// ko bhi camera lagana he    

    int solver(TreeNode *root, int& camera){
        
        if(root == NULL) return 1;
        
        int lchild = solver(root->left, camera);
        int rchild = solver(root->right, camera);
        
        
        // cout << lchild << " " << rchild << endl;
        if(lchild == -1 || rchild == -1){                  // if even any 1 child need (parent brought)
            camera++;
            return 0;
        }
        
        else if(lchild == 0 || rchild == 0) return 1;     // if any child has (parent is doing nothing)                           
    return -1;    // na bacho pe he, na unko chahiye (leaf nodes)
    }
    
    
    int minCameraCover(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL) return 1;
        
        int camera = 0;
        if(solver(root, camera) == - 1) camera++;    // root ko bhi chahiye,  ex : [0,null,0,null,0,null,0]
        // solver(root, camera);
        
    return camera;
    }
};




