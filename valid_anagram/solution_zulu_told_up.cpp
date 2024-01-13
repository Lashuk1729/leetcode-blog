class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> unique_char;
        for(auto ch: s)
            unique_char[ch] += 1;
        
        for(auto ch: t)
            unique_char[ch] -= 1;
        
        for(auto iter: unique_char)
        {
            if(iter.second > 0)
                return false;
        }
        return true;
    }
};