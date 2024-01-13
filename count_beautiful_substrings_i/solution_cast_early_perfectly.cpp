class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.length();
        int count = 0;
        vector<pair<int, int>> cumulative = {{0, 0}};

        // Compute cumulative counts of vowels and consonants
        for (int i = 1; i <= n; ++i) {
            int vowel_count = cumulative[i - 1].first + (vowels.find(s[i - 1]) != vowels.end());
            int consonant_count = cumulative[i - 1].second + (vowels.find(s[i - 1]) == vowels.end());
            cumulative.push_back({vowel_count, consonant_count});
        }

        // Calculate beautiful substrings
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int vowels_count = cumulative[j].first - cumulative[i].first;
                int consonants_count = cumulative[j].second - cumulative[i].second;

                if (vowels_count == consonants_count && vowels_count * consonants_count % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};