class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pos_ast;
        bool flag = false;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0)
                pos_ast.push(asteroids[i]);
            
            else if(asteroids[i] < 0 && pos_ast.empty())
                pos_ast.push(asteroids[i]);
            
            else if(asteroids[i] < 0) {
                if(pos_ast.top() < 0) {
                    pos_ast.push(asteroids[i]);
                    continue;
                }
                
                int t = pos_ast.top();
                if(t > -1*asteroids[i])
                    continue;

                else if(t == -1*asteroids[i]) {
                    pos_ast.pop();
                }

                else {
                    while(!pos_ast.empty() && t > 0 && t < -1*asteroids[i]) {
                        pos_ast.pop();
                        if(!pos_ast.empty())
                            t = pos_ast.top();
                        else
                            break;
                    }
                    if(t > -1*asteroids[i])
                        continue;

                    else if(t == -1*asteroids[i])
                        pos_ast.pop();

                    else{
                        pos_ast.push(asteroids[i]);
                        cout << asteroids[i] << endl;
                    }
                }
            }
        }
        vector<int> res;
        while(!pos_ast.empty()) {
            cout << pos_ast.top() <<" ";
            res.push_back(pos_ast.top());
            pos_ast.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};