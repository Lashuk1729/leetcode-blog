#include <bits/stdc++.h>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, len1 = word1.length(), len2 = word2.length();
        string res;
        while(i < len1 && j < len2){
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while(j < len2){
            res.push_back(word2[j++]);
        }
        while(i < len1){
            res.push_back(word1[i++]);
        }
        return res;
    }
};