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
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int& diameter) {
        //base case
        if (!root) return 0;

        //calculate left and right
        int left = 0, right = 0;
        if (!!root->left) left = height(root->left, diameter);
        if (!!root->right) right = height(root->right, diameter);

        //calculate diameter
        diameter = max(diameter, left + right);

        //return subtree height
        return 1 + max(left, right);
    }
};
