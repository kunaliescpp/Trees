/*
Problem Link: https://www.lintcode.com/problem/854/

Closest Leaf in a Binary Tree

Given a binary tree where every node has a unique value, and a target key k.

Find the value of the nearest leaf node to target k in the tree. If there are multiple cases, you should follow these priorities:
The leaf node is in the left subtree of the node with k;
The leaf node is in the right subtree of the node with k;
The leaf node is not in the subtree of the node with k.
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000][1,1000].
There exists a node in the given binary tree for which node.val == k.
A node is called a leaf if it has no children.

Example 1:
Input: {1, 3, 2}, k = 1
Output: 3
Explanation:
    1
   / \
  3   2
  
Example 2:
Input: {1}, k = 1
Output: 1
*/

class Solution {
    public:
    // priority Order = left -> right-> root
    TreeNode *dfs(TreeNode *root, int k, unordered_map<TreeNode*, TreeNode*>& parent){

        if(root->val == k) return root;

        if(root->left != NULL){
            parent[root->left] = root;
            TreeNode* lc = dfs(root->left, k, parent);
            if(lc != NULL) return lc;
        }

        if(root->right != NULL){
            parent[root->right] = root;
            TreeNode* rc = dfs(root->right, k, parent);
            if(rc != NULL) return rc;
        }

    return NULL;
    }

    int findClosestLeaf(TreeNode *root, int k) {
        
        unordered_map<TreeNode*, TreeNode*>parent;  // target to parent mapping
        
        //searching target node
        TreeNode *knode = dfs(root, k, parent); 

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(knode);
        visited[knode] = true;
        while(!q.empty()){
            
            TreeNode* f = q.front(); q.pop();
            if(f->left == NULL && f->right == NULL) return f->val;

            if(f->left != NULL && visited.count(f->left) == 0){
                visited[f->left] = true;
                q.push(f->left);
            } 

            if(f->right != NULL && visited.count(f->right) == 0){
                visited[f->right] = true;
                q.push(f->right);
            } 

            if(parent.count(f) == 1 && visited.count(parent[f]) == 0){
                visited[parent[f]] = true;
                q.push(parent[f]);
            }
        }

    return -1;
    }
};


