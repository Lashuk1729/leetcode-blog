class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = -1, len_c = candies.size();
        vector<bool> result(len_c, false);
        for(int i = 0; i < len_c; i++){
            if(candies[i] > max)
                max = candies[i];
        }
        for(int i = 0; i < len_c; i++)
        {
            result[i] = candies[i] + extraCandies >= max;
        }
        return result;
    }
};