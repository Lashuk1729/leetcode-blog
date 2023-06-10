class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> success_res (spells.size(), 0);
        int full = potions.size();
        for(int i = 0; i < spells.size(); i++)
        {
            int low = 0, high = potions.size() - 1, mid, num = full;
            while(low <= high){
                mid = low + (high - low) / 2;
                long long res = (long long) potions[mid] * spells[i];
                if (res >= success){
                    num = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            success_res[i] = full - num;
        }
        return success_res;
    }
};