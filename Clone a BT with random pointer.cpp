/*
Problem Link: https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1

Clone a Binary Tree 

Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.
*/
  
class Solution{
  public:
  
    Node *get_root_of_copied_tree(Node *root, unordered_map<Node *, Node *>& mp){
        
        if(root == NULL) return NULL;
        
        mp[root] = new Node (root->data);
        mp[root]->left = get_root_of_copied_tree(root->left, mp);
        mp[root]->right = get_root_of_copied_tree(root->right, mp);
    
    return mp[root];
    }
    
    void connect_random_nodes(Node *root, unordered_map<Node *, Node *>& mp){
        
        if(root == NULL) return;
        
        mp[root]->random = mp[root->random];
        connect_random_nodes(root->left, mp);
        connect_random_nodes(root->right, mp);
    }
    
    Node* cloneTree(Node* tree){
      
      if(tree == NULL) return NULL;
      
      unordered_map<Node *, Node *>mp;             // mp<original node, copied node>
      
      Node *clone_root = get_root_of_copied_tree(tree, mp);
      connect_random_nodes(tree, mp);
      
    return clone_root;
    }
};

