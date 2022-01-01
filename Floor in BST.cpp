/*
Problem Link: https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?leftPanelTab=1

Floor in BST 

Given a Binary search tree and a value X,  the task is to complete the function which will return the floor of x.

Note: Floor(X) is an element that is either equal to X or immediately smaller to X. If no such element exits return -1.

Example 1:
Input:
       8
     /  \
    5    9
   / \    \
  2   6   10
X = 3
Output: 2
Explanation: Floor of 3 in the given BST is 2

Example 2:
Input:
       3
     /   \
    2     5
        /  \
       4    7
      /
     3
X = 1
Output: -1
Explanation: No smaller element exits


Constraints:
1 <= Number of nodes <= 10^5
1 <= X, Value of Node <= 10^6
*/

void solver(TreeNode<int>* root, int key, int &ans){
    
    if(root == NULL) return;
    
    if(root->val <= key) ans = max(ans, root->val); 
    
    if(key < root->val) solver(root->left, key, ans);
    if(key > root->val) solver(root->right, key, ans);
}

int floorInBST(TreeNode<int> * root, int key){ 
    int ans = -1;
    solver(root, key, ans);
    
return ans;
}


