class Solution {
public:
    int string2Int(string num) {
        int n = num.length() - 1;
        int bin = 0;
        for(int i = 0; i < num.length(); i++) {
            bin += pow(2, n-i) * (num[i] - '0');
        }
        return bin;
    }

    int divide_2(int min_n, int max_n, set<int>& unique_num) {
        if(unique_num.find(min_n) == unique_num.end())
            return min_n;
        else
            return divide_2(min_n + 1 + (max_n - min_n)/2, max_n, unique_num);

        if(unique_num.find(max_n) == unique_num.end())
            return max_n;
        else
            return divide_2(min_n, min_n + -1 + (max_n - min_n)/2, unique_num);
    }

    string int2String(int num) {
        string res = "";
        while(num >= 1) {
            int rem = num % 2;
            res = string(1, rem ? '1':'0') + res;
            num = num / 2;
        }
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int len_str = nums[0].length();
        int min_n = 0, max_n = pow(2, len_str) - 1;
        int n = nums.size();
        set<int> unique_num;
        for(int i = 0; i < n; i++)
            unique_num.insert(string2Int(nums[i]));
        
        int ans = divide_2(min_n, max_n, unique_num);
        
        string res = int2String(ans);
        if(res.length() == len_str)
            return res;
        else{
            while(res.length() < len_str) {
                res = string(1, '0') + res;
            }
            return res;
        }
    }
};