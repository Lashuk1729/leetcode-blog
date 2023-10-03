class Solution {
public:
    int sum_row(vector<int>& row_mat) {
        int n = row_mat.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += row_mat[i];
        return sum;
    }

    static bool comp(const pair<int,int>& a, const pair<int,int>& b) {
        if(a.first == b.first)
            return a.second < b.second;

        return a.first < b.first;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        int n = mat.size();
        vector<pair<int, int>> umap;
        for(int i = 0; i < mat.size(); i++)
            umap.push_back(make_pair(sum_row(mat[i]), i));

        sort(umap.begin(), umap.end(), comp);
        for(int i = 0; i < umap.size(); i++)
            cout << umap[i].first <<" "<< umap[i].second << endl;
        
        for(int i = 0; i < k; i++)
            res.push_back(umap[i].second);

        return res;
    }
};