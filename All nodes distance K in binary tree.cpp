/*
Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values
of all nodes that have a distance k from the target node.
You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/


class Solution {
public:
    
    // Time complexity: O(2*n)
    // Space complexity: O(n)
    void printKLevelsDown(TreeNode *node, int k, TreeNode *blocker, vector<int>& v){
        
        if(node == NULL || k < 0 || node == blocker) return;
        
        if(k == 0) v.push_back(node->val);
        
        printKLevelsDown(node->left, k-1, blocker, v);
        printKLevelsDown(node->right, k-1, blocker, v);
    }
    
    //we find path from root to target node
    bool find(TreeNode* root, TreeNode* x, vector<TreeNode *>& vec){                              //[5, 3]
        
        if(root == NULL) return false;
        
        if(root == x){
           vec.push_back(root);
           return true;
        } 
    
        bool filc = find(root->left, x, vec);                                          
        if(filc == true){
            vec.push_back(root);
            return true;
        } 
        
        bool firc = find(root->right, x, vec);
        if(firc == true){
            vec.push_back(root);
            return true;
        }
        
    return false;
    }
    
    //all nodes k distance away from target, k-1 dis away from target 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<TreeNode *> path;
        find(root, target, path);     // path = [5,3]
        
        vector<int> v;
        for(int i = 0; i < path.size(); i++){
            printKLevelsDown(path[i], k-i, (i == 0) ? NULL : path[i-1], v);      // k level down of 5 is -> 7,4                                                                                                // k level down of 3 is -> 1,as 5 act as blocker
        }
    return v;
    }
};




