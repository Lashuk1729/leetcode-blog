class Solution {
public:
    bool winnerOfGame(string colors) {
        int pickA = 0, pickB = 0;
        int n = colors.length();
        for(int i = 0; i < n; i++) {
            if(i != 0 && i != n-1) {
                if(colors[i] == 'A')
                    if(colors[i-1] == 'A' && colors[i+1] == 'A')
                        pickA += 1;
                
                if(colors[i] == 'B')
                    if(colors[i-1] == 'B' && colors[i+1] == 'B')
                        pickB += 1;
            }
        }
        if(pickA > pickB)
            return true;
        
        else
            return false;
    }
};