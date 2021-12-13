/*
Problem Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

Binary Tree to DLL 

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as 
previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Example 1:
Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2

Example 2:
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

class Solution{
    public: 
    
    void solver(Node *root, Node *&head, Node *&prv){
        
       if(root == NULL) return;
       
       solver(root->left, head, prv);
       
       if(prv == NULL) head = root;
       else {
           root->left = prv;
           prv->right = root;
       }
        prv = root;
        
        solver(root->right, head, prv);  
    }
    
    Node *bToDLL(Node *root){
      
       Node* head = NULL;
       Node* prv = NULL;
       solver(root, head, prv);
    
    return head;  
    }
};


