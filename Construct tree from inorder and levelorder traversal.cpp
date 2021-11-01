/*
Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1

Construct tree from Inorder and LevelOrder 

Given inorder and level-order traversals of a Binary Tree, construct the Binary Tree and return the root Node. 


Constraints:
1 <= T <= 100
1 <= N <= 100

Example 1:
Input:
2
3
1 0 2 
0 1 2 
7
3 1 4 0 5 2 6 
0 1 2 3 4 5 6 
Output:
0 1 2
0 1 3 4 2 5 6
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
            if(level[inorder[i]] < level[inorder[inIndex]]){         // x < level[3]
                inIndex = i;                                         // inIndex = 3
            }
        }
    
        Node *node = new Node (inorder[inIndex]);
        if(is == ie) return node;
        
        node->left = CTree(inorder, level, is, inIndex - 1);  //if(is > inIndex-1)return NULL
        node->right = CTree(inorder, level, inIndex + 1, ie); //if(index+1 > ie) return NULL
        
return node;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){
      
      unordered_map<int, int> level;
      for(int i = 0; i < n; i++){
          level[levelOrder[i]] = i;
      }
      
      Node* root = CTree(inorder, level, 0, n-1);
return root;
}


