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
    pair<int, int> counter_avg(TreeNode* node, int& res) {
        if(node == NULL)
            return {0, 0};
        
        auto left = counter_avg(node->left, res);
        auto right = counter_avg(node->right, res);

        int sum = left.first + right.first + node->val;
        int count = 1 + left.second + right.second;
        res += node->val == sum / count;

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        counter_avg(root, res);
        return res;
    }
};