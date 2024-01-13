class Solution {
public:
    bool halvesAreAlike(string s) {
        int left = 0, right = s.length() - 1;
        int vowel1 = 0, vowel2 = 0;
        while(left < right) {
            if(s[left] == 'a' || s[left] == 'A')
                vowel1 += 1;
            else if(s[left] == 'e' || s[left] == 'E')
                vowel1 += 1;
            else if(s[left] == 'i' || s[left] == 'I')
                vowel1 += 1;
            else if(s[left] == 'o' || s[left] == 'O')
                vowel1 += 1;
            else if(s[left] == 'u' || s[left] == 'U')
                vowel1 += 1;

            if(s[right] == 'a' || s[right] == 'A')
                vowel2 += 1;
            else if(s[right] == 'e' || s[right] == 'E')
                vowel2 += 1;
            else if(s[right] == 'i' || s[right] == 'I')
                vowel2 += 1;
            else if(s[right] == 'o' || s[right] == 'O')
                vowel2 += 1;
            else if(s[right] == 'u' || s[right] == 'U')
                vowel2 += 1;
            
            left += 1;
            right -= 1;
        }
        return vowel1 == vowel2;
    }
};