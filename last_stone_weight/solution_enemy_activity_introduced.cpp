class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> sort_stones;
        for(int i = 0; i < stones.size(); i++)
            sort_stones.push(stones[i]);
        
        int temp;
        while(sort_stones.size() - 1)
        {
            int n1 = sort_stones.top();
            sort_stones.pop();
            int n2 = sort_stones.top();
            sort_stones.pop();
            temp = n1 - n2;
            if(temp > 0)
                sort_stones.push(temp);
            
            if(sort_stones.empty())
                break;
        }
        if(!sort_stones.empty())
            return sort_stones.top();
        else
            return 0;
    }
};