class Solution {
public:
    int longestString(int x, int y, int z) {
        int min_xy = min(x, y);
        int max_xy = max(x, y);
        if(min_xy != max_xy)
            return (2*min_xy + 1) * 2 + 2*z;
        else
            return (2*min_xy) * 2 + 2*z;
        // if(max_xy > z) {
        //     if(min_xy + z >= max_xy)
        //         return (z+min_xy+max_xy) * 2;
        //     else
        //         cout << (2*min_xy + 1) * 2 + 2*z
        //         return (2*min_xy + 1) * 2 + 2*z;
        // } 
        // else {
        //     return (z + min_xy) * 2;
        // }
    }
};