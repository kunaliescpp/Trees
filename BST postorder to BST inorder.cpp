/*
Problem Link: https://practice.geeksforgeeks.org/problems/construct-bst-from-post-order/1

Construct BST from Postorder 

Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be 
inorder traversal of the constructed BST.

Example 1:
Input: 6 , 1 7 5 50 40 10
Output: 1 5 7 10 40 50
Explanation: The BST for the given post order traversal is:
	    10
	   /  \
	  5    40 
	 / \     \
	1   7     50
Thus the inorder traversal of BST is: 1 5 7 10 40 50


Constraints:
1 <= T <= 100
1 <= N <= 100
*/

/*
struct Node{
	int data;
	Node *left, *right;
};*/

Node *cTree (int post[], int &postIndex, int lr, int rr){
    
    if(postIndex < 0 || post[postIndex] < lr || post[postIndex] > rr) return NULL;
     
    Node *curr = new Node (post[postIndex--]);
    curr->right = cTree(post, postIndex, curr->data, rr);  
    curr->left = cTree(post, postIndex, lr, curr->data);   
                                                             
return curr;    
}

//Tree dress up in : BST fashion + Postorder fashion
Node *constructTree (int post[], int size){
   
    int postIndex = size - 1;
    int lr = -1e9, rr = 1e9;
    Node *root = cTree(post, postIndex, lr, rr);
   
   return root;
}


