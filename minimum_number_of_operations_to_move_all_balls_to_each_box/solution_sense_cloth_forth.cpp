class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> min_oper(boxes.length(), 0);
        for(int i = 0; i < boxes.length(); i++)
        {
            for(int j = 0; j < boxes.length(); j++)
            {
                if(i != j)
                {
                    if(boxes[j] == '1')
                        min_oper[i] += abs(i - j);
                }
            }
        }
        return min_oper;
    }
};