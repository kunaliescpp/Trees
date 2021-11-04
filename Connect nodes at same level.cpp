/*
Problem Link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

Connect Nodes at Same Level 

Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right 
for each node.
       10                       10 ----> NULL
      / \                       / \
     3   5       =>            3-->5 ---> NULL
    / \   \                   / \   \
   4   1   2                 4-->1-->2 ---> NULL

Example 1:
Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
       / \
      1-->2 -----> NULL
      
Example 2:
Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
         10 ------> NULL
        /  \
       20-->30 ---> NULL
      /  \
     40 ->60 -----> NULL


Constraints:
1 ≤ Number of nodes ≤ 10^5
0 ≤ Data of a node ≤ 10^5
*/

class Solution{
    public:
    //connect nodes at same level.
//        10
//       /  \
//      3--->5    
//     / \    \
//    4-->1---->2   
    void connect(Node *root){
       
        if(root == NULL) return;
       
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
           
            int cnt = q.size();
            Node *prv = NULL;
            
            while(cnt--){
                Node *f = q.front(); q.pop();
                
                if(prv != NULL) prv->nextRight = f;
                
                prv = f;
                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
            }
        } // queue is empty
    }    
};


