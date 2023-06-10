class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret_s = s;
        for(int i = 0; i < indices.size(); i++)
        {
            ret_s[indices[i]] = s[i];
        }
        return ret_s;
    }
};