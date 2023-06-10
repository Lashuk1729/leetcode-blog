class Solution {
public:
    bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
        return v1[1] > v2[1];
    }
    
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums[0].size(), n_size = nums.size();
        for(int i = 0; i < n_size; i++){
            sort(nums[i].begin(), nums[i].end());
        }
        
        int count = 0;
        for(int i = n-1; i >= 0; i--) {
            priority_queue<int> pq;
            for(int j = 0; j < n_size; j++)
                pq.push(nums[j][i]);
            
            count += pq.top();
        }
        
        return count;
    }
};