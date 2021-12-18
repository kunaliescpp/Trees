/* 
Problem Link: https://www.lintcode.com/problem/921/

Count Univalue Subtrees

Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

Example1:
Input:  root = {5,1,5,5,5,#,5}
Output: 4
Explanation:
              5
             / \
            1   5
           / \   \
          5   5   5
          
Example2: 
Input:  root = {1,3,2,4,5,#,6}
Output: 3
Explanation:
              1
             / \
            3   2
           / \   \
          4   5   6

 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    
    bool solver(TreeNode* root, int& cnt){
        
        if(root == NULL) return true;
         
        bool check1 = solver(root->left, cnt);
        bool check2 = solver(root->right, cnt);

        if(check1 && check2){
           if((root->left == NULL || root->left->val == root->val) && (root->right == NULL || root->right->val == root->val)){
              cnt++;
              return true;
           }
        }

    return false;
    }

    //Univalue = universal value : single value subtree
    // leaf is always a Univalue subtree
    int countUnivalSubtrees(TreeNode * root) {
        
        int cnt = 0;
        solver(root, cnt);
    return cnt;
    }
};


