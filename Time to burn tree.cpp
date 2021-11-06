/*
Problem Link: https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563

Time To Burn Tree

You have been given a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn. Given that the Start node 
will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.
It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.

Example 1:
For the given binary tree: [1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1]
Start Node: 3

    1
   / \
  2   3
     / \
    4   5

Output: 2

Explanation : In the zeroth minute, Node 3 will start to burn.
After one minute, Nodes (1, 4, 5) that are adjacent to 3 will burn completely.
After two minutes, the only remaining Node 2 will be burnt and there will be no nodes remaining in the binary tree. 
So, the whole tree will burn in 2 minutes.

Constraints :
1 <= N <= 10^5
1 <= Value of Tree Node <= 10^9
1 <= Value of Start Node <= 10^9
*/

#include<unordered_map>

//dist of the farthest node from the starting node
void inorder(BinaryTreeNode<int>* root, unordered_map<int, vector<int>>& adj){
    
    if(root == NULL) return;   
    
    inorder(root->left, adj);
    
    if(root->left != NULL){
        adj[root->data].push_back(root->left->data);
        adj[root->left->data].push_back(root->data);
    }

    if(root->right != NULL){
        adj[root->data].push_back(root->right->data);
        adj[root->right->data].push_back(root->data);
    }
 
    inorder(root->right, adj);
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start){
    
    unordered_map<int, vector<int>> mp;
    inorder(root, mp);
    
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(start);
    int cnt = 0;
    visited[start] = true;
    while(!q.empty()){
        int k = q.size();
        for(int i = 0; i < k; i++){
            int node = q.front(); q.pop();
            for(int x : mp[node]){
                if(visited[x] == false){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        cnt++;
    } // q is empty

return cnt-1;   //target node not included
}


