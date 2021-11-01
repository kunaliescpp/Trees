/*
Problem Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

Maximum Difference Between Node and Ancestor

Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| 
and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:
The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 10^5
*/


class Solution {
public:
    

    void solver(TreeNode* root, int mini, int maxi, int& diff){

        if(root == NULL) return;
        
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        
        // cout << mini << " " << maxi << endl;
        
        diff = max(diff, abs(maxi - mini));
        
        solver(root->left, mini, maxi , diff);
        solver(root->right, mini, maxi, diff);
    }

    int maxAncestorDiff(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int diff = INT_MIN;
        int mini = INT_MAX, maxi = 0;    
        solver(root, mini, maxi, diff);
        
    return diff;   
    }
};



