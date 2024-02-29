// 513. Find Bottom Left Tree Value
// Solved
// Medium
// Topics
// Companies
// Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

// Example 1:


// Input: root = [2,1,3]
// Output: 1
// Example 2:


// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -2^31 <= Node.val <= 2^31 - 1

#include <iostream>
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
    pair<int,int> solve(TreeNode* root){
        if (root->left == NULL && root->right == NULL){
            return {root->val,1};
        }
        if (root->left == NULL){
            pair<int,int> rightAns = solve(root->right);
            rightAns.second+=1;
            return rightAns;
        }
        if (root->right == NULL){
            pair<int,int> leftAns = solve(root->left);
            leftAns.second+=1;
            return leftAns;
        }
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);

        if (leftAns.second < rightAns.second){
            return {rightAns.first, 1+rightAns.second};
        }

        return {leftAns.first, 1+leftAns.second};

    }
public:
    int findBottomLeftValue(TreeNode* root) {
        return (solve(root).first);
    }
};