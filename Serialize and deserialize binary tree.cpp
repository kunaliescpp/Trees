/*
Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in 
a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another 
computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization
algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized 
to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow 
this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [1,2]
 

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-1000 <= Node.val <= 1000
*/

/*
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};
*/

  
class Codec {
public:

    //Encodes tree-> string
    string serialize(TreeNode* root) {       
        
        if(root == NULL) return "";
        
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            TreeNode* curr = q.front(); q.pop();
            if(curr == NULL) str += "#,";
            else str += to_string(curr->val) + ',';
            
            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);    
            }
        }
        
    return str;  
    }

    //Decodes encoded data-> tree
    TreeNode* deserialize(string data) {    
        
        if(data.size() == 0) return NULL;
        
        stringstream s(data);    // divide string 'data' into no. of strings
        string str;
        getline(s, str, ',');    // str is changing its value after every ','
        
        TreeNode* root = new TreeNode (stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            getline(s, str, ','); 
            if(str == "#"){
                node->left = NULL;
            } else{
                TreeNode* l = new TreeNode (stoi(str));
                node->left = l;
                q.push(l);
            }
            
            getline(s, str, ','); 
            if(str == "#"){
                node->right = NULL;
            } else{
                TreeNode* r = new TreeNode (stoi(str));
                node->right = r;
                q.push(r);
            }
        } // queue is empty
    return root;
    }
};



