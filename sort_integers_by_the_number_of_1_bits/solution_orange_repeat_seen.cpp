class Solution {
public:
    int count_ones(int n) {
        int rem = 0;
        while(n > 0) {
            rem += n % 2;
            n /= 2;
        }
        return rem;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto compare = [this](int low, int high) {
            int count_low = count_ones(low);
            int count_high = count_ones(high);
            if(count_low != count_high)
                return count_low > count_high;

            return low > high;

        };

        priority_queue<int, vector<int>, decltype(compare)> sort_one(compare);
        int n = arr.size();
        for(int i = 0; i < n; i++)
            sort_one.push(arr[i]);

        vector<int> res;
        while(!sort_one.empty()) {
            res.push_back(sort_one.top());
            sort_one.pop();
        }
        return res;
    }
};