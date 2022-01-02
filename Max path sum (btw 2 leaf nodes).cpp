/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

Maximum Path Sum between 2 Leaf Nodes 

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node
to another leaf node.
Note: Here Leaf node is a node which is connected to exactly one different node.

Example 1:
Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation: Maximum Sum lies between leaf node 4 and 5. 4 + 4 + 3 + 5 = 16.

Example 2:
Input:    
            -15                               
         /      \                          
        5         6                      
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  
Output:  27
Explanation: The maximum possible sum from one leaf node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)


Constraints:
2  ≤  Number of nodes  ≤  10^4
-10^3  ≤ Value of each node ≤ 10^3
*/

class Solution{
public:

    int solver(Node* root, int& ans){
        
        if(root == NULL) return 0;
        
        int a = solver(root->left, ans);
        int b = solver(root->right, ans);
    
        if(root->left == NULL)  return b + root->data;
        if(root->right == NULL) return a + root->data;
        
        int currSum = a+b+root->data;    
        ans = max(ans, currSum);        // if parent root has both the children : then check path sum
        
    return max(a+root->data, b+root->data);
    }

    int maxPathSum(Node* root){
        
        int ans = INT_MIN;
        int x = solver(root, ans);
                                                
    return (ans == INT_MIN) ? x : ans; 
    }
};
                                                    
//         1
//        /
//       2
//      /
//     3
//    /
//   4            -> it will return INT_MIN


