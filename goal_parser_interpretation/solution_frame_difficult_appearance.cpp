class Solution {
public:
    string interpret(string command) {
        string S = "";
        for(int i = 0; i < command.length(); i++)
        {
            if(command[i] == 'G')
                S += "G";
            else if(command[i] == '(')
            {
                i += 1;
                if(command[i] == 'a')
                {
                    S += "al";
                    i += 2;
                }    
                else if(command[i] == ')')
                    S += "o";
            }
        }
        cout << S << endl;
        return S;
    }
};