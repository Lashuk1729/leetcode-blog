class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_n = s.length(), t_n = t.length();
        if(s_n == 0)
            return t[0];

        unordered_map<char, int> umap;
        for(int i = 0; i < s_n; i++)
            umap[s[i]] += 1;

        char ele;
        for(int i = 0; i < t_n; i++)
        {
            if(umap.find(t[i]) != umap.end()){
                if(umap[t[i]] > 0)
                    umap[t[i]] -= 1;
                else {
                    ele = t[i];
                    break;
                }
            }
            else {
                ele = t[i];
                break;
            }
        }
        return ele;
    }
};