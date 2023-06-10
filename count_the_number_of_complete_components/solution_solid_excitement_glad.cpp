class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj_list, unordered_set<int>& visited) {
        visited.insert(u);
        for (int v : adj_list[u]) {
            if (visited.count(v) == 0) {
                dfs(v, adj_list, visited);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        int num_components = 0;
        unordered_set<int> visited;
        for (int u = 0; u < n; u++) {
            if (visited.count(u) == 0) {
                num_components++;
                unordered_set<int> component_visited;
                dfs(u, adj_list, component_visited);
                bool is_complete = true;
                for (int v : component_visited) {
                    if (adj_list[v].size() != component_visited.size() - 1) {
                        is_complete = false;
                        break;
                    }
                }
                if (!is_complete) {
                    num_components--;
                }
                visited.insert(component_visited.begin(), component_visited.end());
            }
        }
        return num_components;
    }
};