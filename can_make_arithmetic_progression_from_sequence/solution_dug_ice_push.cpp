class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        priority_queue<int> makeAP;
        for(int i = 0; i < arr.size(); i++) {
            makeAP.push(arr[i]);
        }
        int diff = makeAP.top();
        makeAP.pop();
        diff -= makeAP.top();
        while(makeAP.size() != 1) {
            int curr_diff = makeAP.top();
            makeAP.pop();
            if(curr_diff - makeAP.top() != diff)
                return false;
        }
        return true;
    }
};