/*
Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

Merge two BST's 

Given two BSTs, return elements of both BSTs in sorted form.

Example 1:
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.

Example 2:
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
*/


class Solution{
    public:
     
    void build(vector<int> &v, Node *root){
        
        if(root == NULL) return;
        
        build(v, root->left);
        v.push_back(root->data);
        build(v, root->right);
       
        return;
    }
    
    vector<int>merge_two_vec(vector<int>v1, vector<int>v2){   //merge two sorted array
        
        int m = v1.size();
        int n = v2.size();
        vector<int> v3;
        
        int i = 0, j = 0;
        while(i < m && j < n){
            if(v1[i] >= v2[j]) v3.push_back(v2[j++]);
            
            else v3.push_back(v1[i++]);
        }
        
        while(i < m) v3.push_back(v1[i++]);
        
        while(j < n) v3.push_back(v2[j++]);
        
    return v3;
    }
    
    vector<int> merge(Node *root1, Node *root2){
       
       //inorder of both bst's to obtain two sorted array
       //merge these two sorted array in linear time
       //return this array
       vector<int> v1;
       vector<int> v2;
       
       build(v1, root1);
       build(v2, root2);
       
       return merge_two_vec(v1, v2);            
    }
};


