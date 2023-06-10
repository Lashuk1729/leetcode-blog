class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> bin_vec;
        int rem, count = 0;
        for(int i = 0; i <= n; i++)
        {
            count = 0;
            int temp = i;
            while(temp)
            {
                rem = temp % 2;
                temp /= 2;
                count += rem;
            }
            bin_vec.push_back(count);
        }
        return bin_vec;
    }
};