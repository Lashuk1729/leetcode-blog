class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string> source;
        for(auto path: paths)
            source.insert(path[0]);
        
        string res;
        for(auto path: paths) {
            if(source.find(path[1]) == source.end()) {
                res = path[1];
                break;
            }
        }
        return res;
    }
};