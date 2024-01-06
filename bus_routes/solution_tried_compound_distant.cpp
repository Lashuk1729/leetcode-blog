class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;

        unordered_map<int, vector<int>> connected_route;
        int n = routes.size();
        for(int i = 0; i < n; i++) {
            for(auto iter: routes[i])
                connected_route[iter].push_back(i);
        }

        vector<bool> visited_stops(n, 0);
        queue<int> path;
        path.push(source);
        bool flag = 1;
        int count = 0;

        while(!path.empty()) {
            int size = path.size();
            while(size--) {
                int stop = path.front();
                path.pop();
                if(stop == target)
                    return count;
                
                for(int i : connected_route[stop]){
                    if(!visited_stops[i]) {
                        visited_stops[i] = 1;
                        for(int nextStop : routes[i]){
                            path.push(nextStop);
                        }
                    }
                }
            }
            count += 1;
        }
        return -1;  
    }
};