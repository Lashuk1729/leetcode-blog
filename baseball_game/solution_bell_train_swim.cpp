class Solution {
public:
    int calPoints(vector<string>& ops) {
        // Stack Question
        stack<int> b_score;
        int n = ops.size();
        int num = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(ops[i] == "C")
            {
                b_score.pop();
            }
            else if(ops[i] == "D")
            {
                int temp = b_score.top();
                b_score.push(temp * 2);
            }
            else if(ops[i] == "+")
            {
                int top1, top2, top3;
                top1 = b_score.top();
                b_score.pop();
                top2 = b_score.top();
                b_score.push(top1);
                b_score.push(top1 + top2);
            }
            else
            {
                num = str2num(ops[i]);
                b_score.push(num);
            }
        }
        while(!b_score.empty())
        {
            sum += b_score.top();
            b_score.pop();
        }
        return sum;
    }
    int str2num(string str){
        bool neg = false;
        int sum = 0;
        if(str[0] == '-')
            neg = true;
        else
            sum += str[0] - '0';
        for(int i = 1; i < str.length(); i++)
        {
            sum = sum*10 + (str[i] - '0');
        }
        return neg == true ? -1*sum : sum;
    }
};