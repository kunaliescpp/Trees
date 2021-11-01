/*
Problem Link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

Diagonal Traversal of Binary Tree 

Given a Binary Tree, print the diagonal traversal of the binary tree.
Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree 
belonging to same line.

Example 1:
Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4


Constraints:
1 <= Number of nodes<= 10^5
1 <= Data of a node<= 10^5
*/


vector<int> diagonal(Node *root){
  vector<int>v;
    if(root == NULL) return {};
    
    queue< Node *>q;
    q.push(root);
    
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        
        while(curr != NULL){             // right me niche tak jana he
            v.push_back(curr->data);
            if(curr->left != NULL) q.push(curr->left);
            curr= curr->right;
        }
  
    }
 return v;
}



