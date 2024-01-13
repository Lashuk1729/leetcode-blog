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
 # pragma GCC optimize("O3", "unroll-loop")
class Solution {
public:
    int range_sum(TreeNode* root, int low, int high) {
        if(root == NULL)
            return 0;
        
        if(low <= root->val && root->val <= high)
            return root->val + range_sum(root->left, low, high) + range_sum(root->right, low, high);
        
        else if(low > root->val)
            return range_sum(root->right, low, high);

        else
            return range_sum(root->left, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return range_sum(root, low, high);
    }
};