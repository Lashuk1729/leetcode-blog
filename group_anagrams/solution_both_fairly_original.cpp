class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> uni_anagram;
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            uni_anagram[temp].push_back(strs[i]);
        }

        for(auto iter: uni_anagram) {
            ans.push_back(iter.second);
        }
        
        return ans;
    }
};