/*
Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Left View of Binary Tree 

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited
from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3


Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

//Approach : preOrder traversal kre to 1st node of every level ok he
vector<int> leftView(Node *root)
{
   vector<int>v;
   if(root == NULL) return {};
        queue<Node *>q;
        q.push(root);
        
        while(! q.empty()){
            
            int cnt = q.size();
            
            for(int i = 0; i < cnt; i++){
               Node *curr = q.front();
               q.pop();
               if(i == 0) v.push_back(curr->data);
            
               if(curr->left != NULL) q.push(curr->left);
               if(curr->right != NULL) q.push(curr->right);
            }    
        }
        
   return v;
}


