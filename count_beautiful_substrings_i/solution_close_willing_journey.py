class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        vowels = set('aeiou')
        n = len(s)
        count = 0
        cumulative = [(0, 0)]

        # Compute cumulative counts of vowels and consonants
        for i in range(1, n + 1):
            vowel_count = cumulative[i - 1][0] + (s[i - 1] in vowels)
            consonant_count = cumulative[i - 1][1] + (s[i - 1] not in vowels)
            cumulative.append((vowel_count, consonant_count))

        # Calculate beautiful substrings
        for i in range(n):
            for j in range(i + 1, n + 1):
                vowels_count = cumulative[j][0] - cumulative[i][0]
                consonants_count = cumulative[j][1] - cumulative[i][1]

                if vowels_count == consonants_count and vowels_count * consonants_count % k == 0:
                    count += 1

        return count