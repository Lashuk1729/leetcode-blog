class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dire;
        int n = senate.size();
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R')
                rad.push(i);

            else if(senate[i] == 'D')
                dire.push(i);
        }
        while(rad.size() and dire.size()) {
            if(rad.front() < dire.front()) {
                rad.push(n+rad.front());
            }

            else{
                dire.push(n+dire.front());
            }
            rad.pop();
            dire.pop();
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};