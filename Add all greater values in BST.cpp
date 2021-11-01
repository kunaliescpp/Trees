/*
Problem Link: https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1

Add all greater values to every node in a BST 

Given a BST, modify it so that all greater values in the given BST are added to every node.

Example 1:
Input:
           50
         /    \
        30    70
      /   \   / \  
     20   40 60  80
Output: 350 330 300 260 210 150 80
Explanation:The tree should be modified to
following:
             260
          /       \
        330      150
       /   \   /     \
    350   300 210    80
    
Example 2:
Input:
          2
        /   \
       1     5
            /  \
           4    7
Output: 19 18 16 12 7


Constraints:
1 <= N <= 100000
*/

// modified node = (all nodes >= curr node)
int getSum(Node *root){
    
    if(root == NULL) return 0;
    
    int a = getSum(root->left);
    int b = getSum(root->right);
    
return a+b+root->data;
}

void modifyBst(Node *root, int &adder){
    
    if(root == NULL) return;
    
    //inorder traversal
    modifyBst(root->left, adder);
    adder -= root->data;
    root->data += adder;
    
    modifyBst(root->right, adder);
}

// modify the BST and return its root
Node* modify(Node *root){
    
    int sum = getSum(root);
    modifyBst(root, sum);
    
return root;
}


