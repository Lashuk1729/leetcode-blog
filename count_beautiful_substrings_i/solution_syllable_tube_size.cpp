class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.length();
        int count = 0;
        vector<int> vows(1, 0), cons(1, 0);

        // Compute cumulative counts of vowels and consonants
        for (int i = 1; i <= n; ++i) {
            int vowel_count = vows[i - 1] + (vowels.find(s[i - 1]) != vowels.end());
            vows.push_back(vowel_count);
            int cons_count = cons[i - 1] + (vowels.find(s[i - 1]) == vowels.end());
            cons.push_back(cons_count);
        }

        // Calculate beautiful substrings
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int vowels_count = vows[j] - vows[i];
                int consonants_count = cons[j] - cons[i];

                if (vowels_count == consonants_count && vowels_count * consonants_count % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};