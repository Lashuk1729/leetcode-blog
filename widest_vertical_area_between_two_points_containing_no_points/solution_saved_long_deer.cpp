class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> uniq; 
        
        for (const auto& point : points) {
            uniq.insert(point[0]); 
        }
        
        int maxDiff = 0;
        int prev = INT_MIN;
        
        for (int x : uniq) {
            if (prev != INT_MIN) {
                maxDiff = max(maxDiff, x - prev); 
            }
            prev = x;
        }
        
        return maxDiff;
    }
};