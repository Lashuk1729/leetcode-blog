#include <bits/stdc++.h>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, len1 = word1.length(), len2 = word2.length();
        string res;
        while(i < len1 && j < len2){
            res.append(1, word1[i]);
            i += 1;
            res.append(1, word2[j]);
            j += 1;
        }
        if(i == len1){
            while(j < len2){
                res.append(1, word2[j]);
                j += 1;
            }
        }
        if(j == len2){
            while(i < len1){
                res.append(1, word1[i]);
                i += 1;
            }
        }
        return res;
    }
};