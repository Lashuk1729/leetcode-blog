class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adjacent_list, unordered_map<int,bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);
        for(auto iter: adjacent_list[node]) {
            if(!visited[iter])
                dfs(iter, adjacent_list, visited, ans);
        }
        return;
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacent_list;
        int n = adjacentPairs.size() + 1;

        for(int i = 0; i < n-1; i++) {
            int x = adjacentPairs[i][0], y = adjacentPairs[i][1];
            adjacent_list[x].push_back(y);
            adjacent_list[y].push_back(x);
        }
        unordered_map<int,bool> visited;
        for(auto iter: adjacent_list)
            visited[iter.first] = false;
            
        vector<int> ans;
        int start_node = 0;
        for(auto iter: adjacent_list) {
            if(iter.second.size() == 1) {
                start_node = iter.first;
                break;
            }
        }
        dfs(start_node, adjacent_list, visited, ans);
        return ans;

    }
};