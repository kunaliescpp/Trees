/*
Problem Link: https://practice.geeksforgeeks.org/problems/largest-bst/1

Size of largest BST in a binary tree

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:
Input: 6 6 3 N 2 9 3 N 8 8 2
           6
          / \
         /   \
        /     \
        6       3
        \      / \
         2    9   3
          \   /    \
           8 8      2 
Output: 2
Explanation: The following sub-tree is a BST of size 2: 
       2
      / \        
     N   8


Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6
*/

// v = {left_range, right_range, curr is part of bst or not, curr_size}
vector<int> solver(Node *root, int &ans){
    if(root == NULL) return {INT_MAX, INT_MIN, 1, 0};

    vector<int> lc = solver(root->left, ans);
    vector<int> rc = solver(root->right, ans);

    if(lc[2] && rc[2]){
        if(lc[1] < root->data && root->data < rc[0]){
            int lr = (lc[0] == INT_MAX) ? root->data : lc[0];
            int rr = (rc[1] == INT_MIN) ? root->data : rc[1];

            int size = lc[3] + rc[3] + 1;
            ans = max(ans, size);
            return {lr, rr, 1, size}; 
        }
    }
return {0, 0, 0, 1};
}

int largestBst(Node *root){
    int ans = 0;
    solver(root, ans);

return ans;
}


