/*
Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Top View of Binary Tree 

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes
visible when the tree is viewed from the top. For the given below tree

       1
     /   \
    2     3
   / \   /  \
  4   5 6    7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100


Constraints:
1 ≤ N ≤ 10^5
1 ≤ Node Data ≤ 10^5
*/


class Solution{
   public:
    
  vector<int> topView(Node *root){
      map<int, Node*> mp;
      queue< pair<Node *,int> > q;               // pair <curr node, horizontal dis>
      q.push({root, 0});

      while(!q.empty()){
          auto p = q.front();
          q.pop();

          Node *curr = p.first;
          int hd = p.second;
          if(mp.count(hd) == 0) mp[hd] = curr;

          if(curr->left != NULL) q.push({curr->left, hd-1});
          if(curr->right != NULL) q.push({curr->right, hd+1});
      }

      vector<int>vec;
      for(auto x : mp){
        vec.push_back(x.second->data);
      }
  return vec; 
  }
};

