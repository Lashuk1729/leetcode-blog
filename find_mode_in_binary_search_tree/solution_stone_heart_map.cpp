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
    void tree_traversal_in(TreeNode* node, unordered_map<int, int>& u_nums, int& max_count, vector<int>& res) {
        if(node == NULL)
            return ;
        
        u_nums[node->val] += 1;
        int count = u_nums[node-> val];

        tree_traversal_in(node->left, u_nums, max_count, res);
        
        if(max_count < count) {
            max_count = count;
            res.clear();
            res.push_back(node->val);
        }
        else if(max_count == count)
            res.push_back(node->val);

        tree_traversal_in(node->right, u_nums, max_count, res);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> u_nums;
        vector<int> res;
        int max_count = 0;
        tree_traversal_in(root, u_nums, max_count, res);
        
        // Unnecessary Logic
        /////////////////////////////////////
        // for(auto iter: u_nums)
        //     sort_unums.push_back(make_pair(iter.second, iter.first));

        // sort(sort_unums.begin(), sort_unums.end(), greater<pair<int, int> >());
        // int n = sort_unums.size();
        // vector<int> res;
        // res.push_back(sort_unums[0].second);
        // for(int i = 1; i < n; i++) {
        //     if(sort_unums[0].first == sort_unums[i].first)
        //         res.push_back(sort_unums[i].second);
        // }
        /////////////////////////////////////
        return res;
    }
};