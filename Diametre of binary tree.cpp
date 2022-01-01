/*
Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

Diameter of a Binary Tree 

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 

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
  
    int count_nodes(Node* root, int& ans){
        
        if(root == NULL) return 0;
        
        int cnt1 = count_nodes(root->left, ans);
        int cnt2 = count_nodes(root->right, ans);
        
        ans = max(ans, cnt1+cnt2+1);
        
    return 1 + max(cnt1, cnt2);
    }
  
    //diameter of a Binary Tree = longest path btw two leaf nodes
    int diameter(Node* root) {
        
        int ans;
        count_nodes(root, ans);
        
    return ans;
    }
};


