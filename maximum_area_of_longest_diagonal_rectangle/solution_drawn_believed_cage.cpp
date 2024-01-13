class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        priority_queue<pair<float, int>> diag_area;
        for(int i = 0; i < n; i++) {
            diag_area.push({sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]), dimensions[i][0]*dimensions[i][1]});
        }
        return diag_area.top().second;
    }
};