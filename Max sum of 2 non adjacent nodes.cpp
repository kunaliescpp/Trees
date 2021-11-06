/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

Maximum sum of Non-adjacent nodes 

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of 
chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if 
we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.                                           

Example 1:
Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of node 11.

Example 2:
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of nodes 1 4 5 6 , i.e 16. These nodes are non adjacent.

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
*/

class Solution{
  public:
  
    int solve(Node* root, unordered_map<Node*, int>& dp){
        
        if(root == NULL) return 0;
        if(dp.count(root) == 1) return dp[root];  // memoization
        
        int inc = root->data;
        if(root->left != NULL){
            inc += solve(root->left->left, dp);
            inc += solve(root->left->right, dp);
        }
        
        if(root->right != NULL){
            inc += solve(root->right->left, dp);
            inc += solve(root->right->right, dp);
        }
        
        int exc = solve(root->left, dp) + solve(root->right, dp);
        
        dp[root] = max(inc, exc);
        
    return dp[root];
    }
  
    //max. sum of non-adjacent nodes.
    int getMaxSum(Node *root){
        
        unordered_map<Node*, int> mp;
        int ans = solve(root, mp);
        
    return ans;
    }
};



