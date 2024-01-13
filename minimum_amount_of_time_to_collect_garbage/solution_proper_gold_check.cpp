class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int last_M = 0, last_P = 0, last_G = 0;
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            ans += garbage[i].length();
            if(last_M == 0 && garbage[i].find("M") != garbage[i].npos)
                last_M = i;
            if(last_P == 0 && garbage[i].find("P") != garbage[i].npos)
                last_P = i;
            if(last_G == 0 && garbage[i].find("G") != garbage[i].npos)
                last_G = i;
        }

        for(int i = 0; i < last_M; i++) {
            ans += travel[i];
        }
        
        for(int i = 0; i < last_P; i++) {
            ans += travel[i];
        }

        for(int i = 0; i < last_G; i++) {
            ans += travel[i];
        }

        return ans;
    }
};