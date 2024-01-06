class Solution {
    
public:
    string fizzBuzzNum(int num)
    {
        if(num % 3 == 0 && num % 5 == 0){
            return "FizzBuzz";
        }
        else if(num % 3 == 0)
        {
            return "Fizz";
        }
        else if(num % 5 == 0)
        {
            return "Buzz";
        }
        else
        {
            return to_string(num);
        }
    }
public:
    vector<string> fizzBuzz(int n) {
        vector <string> answer;
        for(int i = 1; i <= n; i++)
        {
            string str = fizzBuzzNum(i);
            answer.push_back(str);
        }
        return answer;
    }
};