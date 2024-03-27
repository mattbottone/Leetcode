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

#include <cmath>
#include <algorithm>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (treeHeight(root) < 0) return false;
        else return true;
    }
private:
    int treeHeight(TreeNode* root) {
        if (!root) return 0;
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        if (left < 0 || right < 0) return -1;
        else if (abs(left - right) > 1) return -1;
        else return 1 + max(left, right);
    }
};
