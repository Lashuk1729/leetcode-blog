class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if(n <= 2 * candidates) {
            long long sum = 0;
            sort(costs.begin(), costs.end());
            for(int i = 0; i < k; i++) {
                sum += costs[i];
            }
            return sum;
        }
        priority_queue<int, vector<int>, greater<int>> 
        pq0(costs.begin(), costs.begin() + candidates),
        pq1(costs.end() - candidates, costs.end());

        long long sum = 0;
        for (int l = candidates, r = n - 1 - candidates; k > 0; k--) {
            int x = pq0.empty() ? INT_MAX : pq0.top();
            int y = pq1.empty() ? INT_MAX : pq1.top();
            
            cout << x <<" "<< y << endl;
            if (x <= y) {
                sum += x;
                pq0.pop();
                if (l <= r)
                    pq0.push(costs[l++]);
            } 
            else {
                sum += y;
                pq1.pop();
                if (l <= r)
                    pq1.push(costs[r--]);
            }
        }
        return sum;
    }
};