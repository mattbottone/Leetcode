/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
#include <algorithm>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int left = 1, right = 1;
        if (root->left != nullptr) left = maxDepth(root->left) + 1;
        if (root->right != nullptr) right = maxDepth(root->right) + 1;
        return max(left, right);

    }
};
