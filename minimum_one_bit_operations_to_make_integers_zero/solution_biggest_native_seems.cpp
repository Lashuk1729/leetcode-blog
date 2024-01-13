class Solution {
public:
    string reverseIntToBin(int n) {
        string res = "";
        while(n) {
            res += string(1, (n % 2) + '0');
            n = n / 2;
        }
        return res;
    }
    int minimumOneBitOperations(int n) {
        string s_bin = reverseIntToBin(n);
        int ind = 0, res = 0, len = s_bin.length();
        
        while(ind <= len) {
            if(s_bin[ind] == '1')
                res = (pow(2, ind+1) - 1) - res;
            ind += 1;
        }

        return res;
    }
};