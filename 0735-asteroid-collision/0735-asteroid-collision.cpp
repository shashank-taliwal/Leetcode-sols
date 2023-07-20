class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int ast: asteroids){
            if(stk.empty()){
                stk.push(ast);
            }
            else{
                while(!stk.empty() and stk.top()>0 and ast<0 and abs(stk.top())<abs(ast)){
                    stk.pop();
                }
                if(!stk.empty() and abs(stk.top())==abs(ast) and stk.top()>0 and ast<0){
                    stk.pop();
                }
                else if(!stk.empty() and stk.top()>0 and ast<0 and abs(stk.top())>abs(ast)){
                    continue;
                }
                else{
                    stk.push(ast);
                }
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};