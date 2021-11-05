/*
Problem Link: https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1

Foldable Binary Tree 

Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right subtrees of the tree are 
structure wise same. An empty tree is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.

(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12
 
Example 1:
Input:
     10
    /    \
   7     15
 /  \   /  \
N   9  11   N
Output:Yes

Example 2:
Input:
      10
    /    \
   7     15
 /  \   /  \
5   N  11   N
Output: No


Constraints:
0 <= n <= 10^3
1 <= data of node <= 10^4
*/

bool solve(Node *root1, Node* root2){
    
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;
    
    bool check1 = solve(root1->left, root2->right);
    bool check2 = solve(root1->right, root2->left);

return (check1 && check2);
}

// A binary tree is foldable or not.
bool IsFoldable(Node* root){
    
    if(root == NULL) return true;
    
    bool ans = solve(root->left, root->right);  

return ans;
}


