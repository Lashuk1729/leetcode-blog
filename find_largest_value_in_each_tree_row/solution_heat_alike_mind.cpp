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
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

    void max_value(TreeNode* root, int level, vector<int>& max_val) {
        if(root == NULL)
            return ;
        
        int curr_level = level;
        max_val[curr_level] = max(max_val[curr_level], root->val);
        max_value(root->left, level + 1, max_val);
        max_value(root->right, level + 1, max_val);
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return {};
            
        int high = height(root);
        vector<int> max_val (high, INT_MIN);
        max_value(root, 0, max_val);
        return max_val;
    }
};