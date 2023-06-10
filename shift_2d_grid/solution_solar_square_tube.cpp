class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> flatten_grid;
        vector<vector<int>> res_grid(grid.size(), vector<int> (grid[0].size(), 0));
        int num, n = grid.size() * grid[0].size() - 1;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
                flatten_grid.push_back(grid[i][j]);
        }
        for(int i = 0; i < k; i++)
        {
            num = flatten_grid[n];
            flatten_grid.pop_back();
            flatten_grid.insert(flatten_grid.begin(), num);
        }
        k = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                res_grid[i][j] = flatten_grid[k];
                k += 1;
            }
        }
        return res_grid;
    }
};