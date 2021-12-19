/*
Problem Link: https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

k-th smallest element in BST 

Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
 

Constraints:
1<=Number of nodes<=100000
*/


class Solution{
  public:
  
    void solve(Node* root, int &k, int &ans){
        
        if(root == NULL) return;
        
        solve(root->left, k, ans);
          
        k--;
        if(k == 0){
            ans = root->data;
            return;
        }
        
        solve(root->right, k, ans);
    }
  
    int KthSmallestElement(Node *root, int k){
      
       int ans = -1;
       solve(root, k, ans);
    
    return ans;
    }
};


