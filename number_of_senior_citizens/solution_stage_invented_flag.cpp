class Solution {
public:
    bool validSeniors(string detail) {
        char ch1 = detail[11], ch2 = detail[12];
        int num = (ch1 - '0') * 10 + (ch2 - '0');
        return num > 60 ? true : false; 
    }
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i < details.size(); i++) {
            count += validSeniors(details[i]);
        }
        return count;
    }
};