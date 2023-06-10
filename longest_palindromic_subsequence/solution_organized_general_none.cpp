class Solution {
public:
    int recur_solve(string& s, vector<vector<int>>&memo_array, int start, int end)
    {
        if (start == end) 
            return 1;
        if (start > end) 
            return 0;
        
        if (memo_array[start][end] != 0)
            return memo_array[start][end];

        if (s[start] == s[end]) 
            memo_array[start][end] = 2 + recur_solve(s, memo_array, start + 1, end - 1);
        else{
            int go_leftright = recur_solve(s, memo_array, start + 1, end);
            int go_rightleft = recur_solve(s, memo_array, start, end - 1);
            memo_array[start][end] = max(go_leftright, go_rightleft);
        }
        return memo_array[start][end];
    }
    int longestPalindromeSubseq(string s) 
    {
        vector<vector<int>> memo_array(s.size() , vector<int> (s.size(), 0));
        int ans = recur_solve(s, memo_array, 0, s.size() - 1);
        return ans;
    }
};