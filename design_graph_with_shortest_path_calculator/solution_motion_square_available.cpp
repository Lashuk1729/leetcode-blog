class Graph {
    unordered_map<int, vector<pair<int, int>>> adjacent_list;

public:
    Graph(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) {
            adjacent_list.operator[](i);
        }
        for(int i = 0; i < edges.size(); i++) {
            adjacent_list[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjacent_list[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        if(node1 == node2)
            return 0;

        vector<int> visited_cost(adjacent_list.size(), INT_MAX);
        visited_cost[node1] = 0;

        queue<int> path;
        path.push(node1);
        visited_cost[node1] = 0;

        while(!path.empty()) {
            int temp = path.front();
            // cout << visited_cost[temp] <<" ";
            path.pop();
            if(temp == node2) {
                continue;
            }
            for(auto iter: adjacent_list[temp]) {
                if(visited_cost[iter.first] > visited_cost[temp] + iter.second) {
                    visited_cost[iter.first] = visited_cost[temp] + iter.second;
                    path.push(iter.first);
                }
            }
        }

        if(visited_cost[node2] == INT_MAX)
            return -1;
        else
            return visited_cost[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */