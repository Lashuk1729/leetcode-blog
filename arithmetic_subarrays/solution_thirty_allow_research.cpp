class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // brute force logic => because no logic came right now to me
        int m = l.size();
        vector<bool> res;
        priority_queue<int> pq;

        for(int i = 0; i < m; i++) {
            
            for(int j = l[i]; j <= r[i]; j++) {
                pq.push(nums[j]);
            }
            bool flag = 0;
            int curr, diff = -1, prev = pq.top(); pq.pop();
            while(!pq.empty()) {
                curr = pq.top();
                pq.pop();
                if(flag == 0) {
                    diff = curr - prev;
                    flag = 1;
                }
                else {
                    if(diff != curr - prev) {
                        res.push_back(0);
                        flag = 0;
                        break;
                    }
                }
                prev = curr;
            }
            if(pq.empty() && flag == 1)
                res.push_back(1);

            else if (!pq.empty()){
                while(!pq.empty())
                    pq.pop();
            }
        }
        return res;
    }
};