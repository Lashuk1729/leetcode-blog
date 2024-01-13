class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> pos_seat;
        int n = corridor.size();
        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S')
                pos_seat.push_back(i);
        }

        if(pos_seat.size() % 2 == 1 || pos_seat.size() == 0)
            return 0;

        long long res = 1;
        int prev = pos_seat[1];
        n = pos_seat.size();
        for(int i = 2; i < n; i += 2) {
            int len = pos_seat[i] - prev;
            res = (res * len) % mod;
            prev = pos_seat[i+1];
        }

        return res % mod;
    }
};