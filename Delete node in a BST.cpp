/*
Problem Link: https://leetcode.com/problems/delete-node-in-a-bst/

Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the 
root node reference (possibly updated) of the BST.

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it. One valid answer is 
[5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.


Constraints:
-10^5 <= key <= 10^5
 */


class Solution {
public:
    //Approach : copy succesor value into root and delete root
    TreeNode *getSuccesor(TreeNode* curr){
        
        curr = curr->right;
        while(curr->left != NULL) curr = curr->left;
    
    return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) return NULL;
        
        //SEARCH
        if(root->val > key) root->left = deleteNode(root->left, key);
        
        else if(root->val < key) root->right = deleteNode(root->right, key);
        
        else { //root->val == key
        //DELETE
            if(root->left == NULL){              //have only right child
                return root->right;
            }
            
            else if(root->right == NULL){        //have only left child
                return root->left;
            }
            
            else { 
                TreeNode *succ = getSuccesor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }  
        }
        
    return root;   
    }
};


