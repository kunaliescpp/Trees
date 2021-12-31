/*
Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1

Construct tree from Inorder and LevelOrder 

Given inorder and level-order traversals of a Binary Tree, construct the Binary Tree and return the root Node. 

Example 1:
Input: in[] = {4, 8, 10, 12, 14, 20, 22}, 
       level[] = {20, 8, 22, 4, 12, 10, 14}

Output: Inorder traversal of the constructed tree is: 4 8 10 12 14 20 22

Explanation: In a Levelorder sequence, the first element is the root of the tree. So we know ’20’ is root for given sequences. 
By searching ’20’ in Inorder sequence, we can find out all elements on left side of ‘20’ are in left subtree and elements on 
right are in right subtree. So we know below structure now. 

             20
           /    \
          /      \ 
 {4,8,10,12,14}  {22}
 
Let us call {4,8,10,12,14} as left subarray in Inorder traversal and {22} as right subarray in Inorder traversal. 
*/

/*Node is as follows:
struct Node{
    int key;
    struct Node* left, *right;
}; */

// Time complexity : O(n^2)
Node* CTree(int inorder[], unordered_map<int, int>& level, int is, int ie){

       if(is > ie) return NULL;
        
        int inIndex = is;
        for(int i = is + 1; i <= ie; i++){
            if(level[inorder[i]] < level[inorder[inIndex]]){     
                inIndex = i;                                        
            }
        }
    
        Node *curr = new Node (inorder[inIndex]);
        curr->left = CTree(inorder, level, is, inIndex - 1); 
        curr->right = CTree(inorder, level, inIndex + 1, ie); 
        
return curr;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){
      
      unordered_map<int, int> level;
      for(int i = 0; i < n; i++){
          level[levelOrder[i]] = i;
      }
      
      Node* root = CTree(inorder, level, 0, n-1);
       
return root;
}


