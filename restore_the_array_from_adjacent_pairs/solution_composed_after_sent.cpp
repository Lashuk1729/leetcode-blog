class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adjacent_list, unordered_map<int, bool>& visited, int start, vector<int>& res) {
        visited[start] = 1;
        res.push_back(start);
        for(auto iter: adjacent_list[start]) {
            if(!visited[iter])
                dfs(adjacent_list, visited, iter, res);
        }
        return;
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacent_list;
        int n = adjacentPairs.size() + 1;
        vector<int> res;

        for(int i = 0; i < n-1; i++) {
            adjacent_list[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            adjacent_list[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        // for(auto iter: adjacent_list) {
        //     cout << iter.first <<": ";
        //     for(int i = 0; i < iter.second.size(); i++) {
        //         cout << iter.second[i] <<", ";
        //     }
        //     cout << endl;
        // }
        
        unordered_map<int, bool> visited;
        for(auto iter: adjacent_list) {
            visited[iter.first] = false;
        }

        int start = 0;
        for(auto iter: adjacent_list) {
            if(iter.second.size() == 1) {
                start = iter.first;
                break;
            }
        }

        // DFS
        dfs(adjacent_list, visited, start, res);
        return res;
    }
};