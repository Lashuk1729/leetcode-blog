class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float, vector<float>, greater<float>> time;
        int n = dist.size();
        for(int i = 0; i < n; i++) {
            float t = ceil(dist[i] / (speed[i]*1.0));
            time.push(t);
        }
        int count = 0, res = 0;
        while(!time.empty()) {
            if(time.top() - count <= 0)
                return res;
            
            else
                res += 1;
            count += 1;
            time.pop();
        }
        return res;
    }
};