class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = haystack.size(), N = needle.size();
        for (int i = 0; i <= M - N; i++) {
            int j = 0;
            for(j = 0; j < N; j++){
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == N)
                return i;
        }
        return -1;
    }
};