class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> freq_count;
        int res = 0;
        for(auto iter: chars)
            freq_count[iter] += 1;

        for(auto iter: words) {
            unordered_map<char, int> temp_count = freq_count;
            bool flag = 1;
            for(auto i: iter) {
                if(temp_count[i] > 0)
                    temp_count[i] -= 1;
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                res += iter.size();
        }
        return res;
    }
};