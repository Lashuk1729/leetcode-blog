class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> greater_stone;
        for(int i = 0; i < stones.size(); i++) {
            greater_stone.push(stones[i]);
        }
        while(greater_stone.size() > 1) {
            int y = greater_stone.top();
            greater_stone.pop();
            int x = greater_stone.top();
            greater_stone.pop();
            if (y - x >= 1) {
                greater_stone.push(y - x);
            }
            else {
                continue;
            }
        }
        return greater_stone.empty() ? 0 : greater_stone.top();
    }
};