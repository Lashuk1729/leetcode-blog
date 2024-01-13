class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curr = 0;
        int l = max(n, target[target.size()-1]);
        for(int i = 1; i <= l; i++) {
            if(curr >= target.size())
                break;
            if(i == target[curr]) {
                res.push_back("Push");
                curr += 1;
            }
            else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};