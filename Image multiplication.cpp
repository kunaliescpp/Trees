/*
Problem Link: https://practice.geeksforgeeks.org/problems/image-multiplication0627/1

Image Multiplication 

You are given a binary tree. Your task is pretty straightforward. You have to find the sum of the product of each node 
and its mirror image (The mirror of a node is a node which exists at the mirror position of the node in opposite subtree 
at the root). Don’t take into account a pair more than once. The root node is the mirror image of itself.

Example 1:
Input:
      4         
    /    \
   5      6
Output: 46
Explanation: Sum = (4*4) + (5*6) = 46

Example 2:
Input:
                       1                 
                   /        \
                 3            2
                  /  \         /  \
              7     6       5    4
            /   \    \     /  \    \
          11    10    15  9    8    12
Output: 332
Explanation: Sum = (1*1) + (3*2) + (7*4) + (6*5) + (11*12) + (15*9) = 332


Constraints:            
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5
*/

/*
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


class Solution{
    
    public:
    
    const int mod = 1e9 + 7;
    void find(Node *root1, Node *root2, long long &sum){
        
        if(!root1 && !root2 || !root1 && root2 || root1 && !root2) return;
        
        sum += (root1->data * root2->data);
        sum = sum % mod;
        
        find(root1->left, root2->right, sum);
        find(root1->right, root2->left, sum);
    }
    
    long long imgMultiply(Node *root){
      
      if(root == NULL) return 0;
      
      long long sum = 0;
      sum += (root->data * root->data);
      sum = sum % mod;
      
      find(root->left, root->right, sum);
      
    return sum;
    }
};


