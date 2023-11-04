class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), req_count;
        vector<int> res;
        unordered_map<int, int> freq_num;
        req_count = int(n/3) + 1;

        cout << req_count << endl;
        
        for(int i = 0; i < n; i++)
            freq_num[nums[i]] += 1;

        unordered_map<int, int>::iterator itr;
        for(itr = freq_num.begin(); itr != freq_num.end(); itr++) {
            if(itr->second >= req_count)
                res.push_back(itr->first);
        }
        return res;
    }
};