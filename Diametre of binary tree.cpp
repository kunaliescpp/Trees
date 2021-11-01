/*
Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

Diameter of a Binary Tree 

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded
(note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Example 1:
Input:
       1
     /  \
    2    3
Output: 3

Example 2:
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4


Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
*/

/*
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;  //(by default NULL in class)
    }
}; */

class Solution {
  public:
  
    int height(Node* root, int& ans){
        
        if(root == NULL) return 0;
        
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        
        ans = max(ans, lh+rh+1);
        
    return 1 + max(lh, rh);
    }
  
    //diameter of a Binary Tree = longest path btw two leaf nodes
    int diameter(Node* root) {
        
        int ans;
        height(root, ans);
        
    return ans;
    }
};




