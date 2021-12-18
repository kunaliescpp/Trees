/*
Problem Link: https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

Find the Closest Element in BST 

Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:
Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has value nearest to K is 11. so the answer is 2

Example 2:
Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
K = 9
Output: 0
Explanation: K=9. The node that has value nearest to K is 9. so the answer is 0.

Constraints:
1 <= Number of nodes <= 100000
*/


class Solution{
  public:
  
  void solver(Node* root, int key, int &ans){
    
    if(root == NULL) return;
    
    solver(root->left, key, ans);
    
    if(ans >= abs(root->data - key)) ans = abs(root->data - key);
    else return;
    
    solver(root->right, key, ans);
  }
   
  int minDiff(Node *root, int key){

      int ans = INT_MAX;
      solver(root, key, ans);

  return ans;
  }
};


