class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        if(ruleKey == "type")
        {
            return count_matches(items, 0, ruleValue);
        }
        else if(ruleKey == "color")
        {
            return count_matches(items, 1, ruleValue);
        }
        else
        {
            return count_matches(items, 2, ruleValue);
        }
        
    }
    
    int count_matches(vector<vector<string>>& items, int j, string val) {
        int count = 0;
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i][j] == val)
                count += 1;
        }
        return count;
    }
};