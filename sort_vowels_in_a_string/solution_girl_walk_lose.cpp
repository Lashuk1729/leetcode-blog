class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> vowel_in;
        string vowels = "AEIOUaeiou";
        string res = "";
        for(int i = 0; s[i] != '\0'; i++) {
            if(vowels.find(s[i]) < vowels.length())
                vowel_in.push(s[i]);
        }
        for(int i = 0; s[i] != '\0'; i++) {
            if(vowels.find(s[i]) < vowels.length()) {
                char ch = vowel_in.top();
                vowel_in.pop();
                res += ch;
            }

            else
                res += s[i];
        }
        return res;
    }
};