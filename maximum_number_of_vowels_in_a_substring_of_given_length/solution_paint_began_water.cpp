class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    int maxVowels(string s, int k) {
        int max_count = 0, count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0) {
                for(int j = 0; j < k; j++) {
                    if(isVowel(s[i+j])) {
                        count += 1;
                    }
                }
                max_count = max(count, max_count);
                i = k - 1;
            }
            else {
                count -= isVowel(s[i-k]) ? 1 : 0;
                if(isVowel(s[i]))
                    count += 1;
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};