/*
Problem Link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

Right View of Binary Tree 

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:
Input:
       1
    /    \
   3      2
Output: 1 2

Example 2:
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60


Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5
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


class Solution
{
    public:
    
    //Time complexity: O(n)
    //Space complexity: O(1)
    vector<int> rightView(Node *root){
        
        vector<int>v;
        if(root == NULL) return v;
        queue<Node *>q;
        q.push(root);
        
        while(! q.empty()){
            
            int cnt = q.size();
            
            for(int i = 0; i < cnt; i++){
               Node *curr = q.front();
               q.pop();
               if(i == cnt-1) v.push_back(curr->data);
            
               if(curr->left != NULL) q.push(curr->left);
               if(curr->right != NULL) q.push(curr->right);
            }    
        }
    return v;
    }
};


