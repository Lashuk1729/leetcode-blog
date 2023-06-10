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
    int max_length = 0;
    void long_zig_zag(TreeNode* node, bool dir, int current_length) {
        if(node == NULL)
            return;

        else
        {
            max_length = max(max_length, current_length);
            long_zig_zag(node->left, false, dir ? current_length + 1 : 1);
            long_zig_zag(node->right, true, dir ? 1 : current_length + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        long_zig_zag(root, false, 0);
        long_zig_zag(root, true, 0);
        return max_length;
    }
};