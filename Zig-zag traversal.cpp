/*
Problem Link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

ZigZag Tree Traversal 

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
Input:
        3
      /   \
     2     1
Output: 3 1 2

Example 2:
Input:
           7
         /   \
        9     7
       / \   /   
      8   8 6     
     / \
    10  9 
Output:
7 7 9 8 8 6 9 10 


Constraints:
1 <= N <= 10^4
*/

class Solution{
    public:
    // Zig zag order traversal of tree = 2 stack approach
    vector <int> zigZagTraversal(Node* root){
    	
    	vector<int> v;
    	
    	stack<Node*> stk1;
    	stack<Node*> stk2;
    	stk1.push(root);
    	while(!stk1.empty() || !stk2.empty()){
    	    while(!stk1.empty()){
    	        Node* f = stk1.top(); stk1.pop();
    	        v.push_back(f->data);
    	        if(f->left != NULL) stk2.push(f->left);
    	        if(f->right != NULL) stk2.push(f->right);
    	    }
    	    
    	    while(!stk2.empty()){
    	        Node* f = stk2.top(); stk2.pop();
    	        v.push_back(f->data);
    	        if(f->right != NULL) stk1.push(f->right);
    	        if(f->left != NULL) stk1.push(f->left);
    	    }
    	}
    	
    return v;
    }
};


