class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, count = 0;
        stack<int> cont_bin;
        while(count < 32)
        {
            cont_bin.push(n % 2);
            n = n / 2;
            count += 1;
        }
        count = 0;
        while(!cont_bin.empty())
        {
            ans += cont_bin.top() * pow(2, count);
            count += 1;
            cont_bin.pop();
        }
        return ans;
    }
};