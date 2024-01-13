class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNum;
        romanNum['I'] = 1;
        romanNum['V'] = 5;
        romanNum['X'] = 10;
        romanNum['L'] = 50;
        romanNum['C'] = 100;
        romanNum['D'] = 500;
        romanNum['M'] = 1000;

        int num = romanNum[s[0]], n = s.length(), prev = 0;
        for(int i = 1; i < n; i++) {
            if(romanNum[s[prev]] < romanNum[s[i]]) {
                num += romanNum[s[i]] - 2 * romanNum[s[prev]];
            }
            else
                num += romanNum[s[i]];
            prev = i;
        }
        return num;
    }
};