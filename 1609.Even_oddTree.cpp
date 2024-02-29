// 1609. Even Odd Tree
// Solved
// Medium
// Topics
// Companies
// Hint
// A binary tree is named Even-Odd if it meets the following conditions:

// The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
// For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
// For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
// Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

 

// Example 1:


// Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
// Output: true
// Explanation: The node values on each level are:
// Level 0: [1]
// Level 1: [10,4]
// Level 2: [3,7,9]
// Level 3: [12,8,6,2]
// Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
// Example 2:


// Input: root = [5,4,2,3,3,7]
// Output: false
// Explanation: The node values on each level are:
// Level 0: [5]
// Level 1: [4,2]
// Level 2: [3,3,7]
// Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.
// Example 3:


// Input: root = [5,9,1,3,5,7]
// Output: false
// Explanation: Node values in the level 1 should be even integers.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 106

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL){
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool isEven = true;

        while(!q.empty()){
            int x = q.size();
            int prev = isEven ? INT_MIN: INT_MAX;

            for (int i = 0;i<x;i++){
                TreeNode* node = q.front();
                q.pop();
                int a = node->val;
                if (isEven){
                    if (!(a%2 != 0 && a>prev))
                        return false;
                }
                else{
                    if (!(a%2 == 0 && a<prev))
                        return false;
                
                }

                if (node->left != NULL){
                    q.push(node->left);
                }
                if (node->right != NULL){
                    q.push(node->right);
                }
                prev = a;
            }
            isEven = !isEven;
        }
        
        return true;
    }
};