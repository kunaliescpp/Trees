/*
Problem Link: https://www.lintcode.com/problem/901/

Closest Binary Search Tree Value II

Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Example 1:
Input: {1}, 0.000000, 1
Output: [1]
Explanation： Binary tree {1},  denote the following structure: 1

Example 2:
Input: {3,1,4,#,2}, 0.275000, 2
Output: [1,2]
Explanation： Binary tree {3,1,4,#,2},  denote the following structure:
  3
 /  \
1    4
 \
  2
 */


class Solution {
    public:   
    //method 1: preorder traversal + priority_queue
    //method 2: Inorder traveral + queue
    void inorder(TreeNode* root, double target, int k, queue<int>& q){
        
        if(root == NULL) return;

        inorder(root->left, target, k, q);

        if(q.size() < k) q.push(root->val);
        else if(abs(q.front()-target)>abs(root->val-target)){
            q.pop();
            q.push(root->val);
        }
        else return;

        inorder(root->right, target, k, q);     
    }

    vector<int> closestKValues(TreeNode * root, double target, int k){
    
        queue<int> q;
        inorder(root, target, k, q);

        vector<int> v;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            v.push_back(f);
        }
      
    return v;
    }
};


