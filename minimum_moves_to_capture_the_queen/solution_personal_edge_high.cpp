class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //rook and queen in same row
        if(a == e && !(a == c && d > min(b,f) && d < max(b,f) )) 
            return 1;
        
        //rook and queen in the same column
        if(b == f && !(b == d && c > min(a,e) && c < max(a,e) ))
            return 1;

        //bishop and queen in the same anti- diagonal
        if(c + d == e + f && !(c + d == a + b && a > min(c , e) && a < max(c, e) ))
            return 1;

        // bishop and queen in the same diagonal
        if(c-d == e-f && !( c-d == a-b && a > min(c , e) && a < max(c, e) ))
            return 1;
    
        return 2;
    }
};