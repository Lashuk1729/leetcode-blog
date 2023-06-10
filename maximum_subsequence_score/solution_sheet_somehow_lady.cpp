class Solution {
public:
    struct myComp {
        constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b)
            const noexcept
        {
            if(a.first == b.first)
                return a.second > b.second;

            else 
                return a.first < b.first;
        }
    };
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i = 0; i < n; i++)
            vec.push_back({nums2[i], nums1[i]});
        
        sort(vec.begin(),vec.end());
        
        long long res = 0,currSum = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=n-1; i>n-1-k; i--)
        {
            pq.push(vec[i].second);
            currSum += vec[i].second;
        }
        
        // score will be sum*(minimum of selected index of nums2[i])
        res = max(res, currSum*vec[n-k].first);
        
        for(int i=n-1-k; i>=0; i--)
        {
            int mini=pq.top();
            pq.pop();
            currSum -= mini;
            
            currSum += vec[i].second;
            pq.push(vec[i].second);
            
            res=max(res,currSum*vec[i].first);
        }
        
        return res;
    }
};