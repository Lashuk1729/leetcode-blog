class Solution {
public:
    int res = 0;
    int dfs(int node, vector<int>&cost)
    {
        if (node>=cost.size()) return 0;
        int L = dfs(2*node+1, cost);
        int R = dfs(2*node+2, cost);
        res += abs(R-L);
        return cost[node]+max(L,R);
    }
    int minIncrements(int n, vector<int>& cost) {
        dfs(0, cost);
        return res;
    }
};