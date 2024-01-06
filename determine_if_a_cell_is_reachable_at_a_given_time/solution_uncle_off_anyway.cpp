class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(t == 1 && sx == fx && sy == fy)
            return false;
        return max(abs(fx-sx), abs(fy-sy)) <= t;
    }
};