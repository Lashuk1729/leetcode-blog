# pragma GCC optimize("03", "unroll-loops")

class Solution {
public:
    bool isPathCrossing(string path) {
        bool result = 0;
        int x_cood = 0, y_cood = 0, n = path.length();
        set<pair<int, int>> position;
        position.insert({0, 0});
        for(int i = 0; i < n; i++) {
            if(path[i] == 'N') y_cood += 1;
            else if(path[i] == 'S') y_cood -= 1;
            else if(path[i] == 'E') x_cood += 1;
            else if(path[i] == 'W') x_cood -= 1;

            if(position.find({x_cood, y_cood}) != position.end()) {
                result = 1;
                break;
            }
            else
                position.insert({x_cood, y_cood});
        }
        return result;
    }
};