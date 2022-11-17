class Solution {
public:
    bool matching_pairs(char opening, char closing){
        if(opening=='(' and closing==')')return true;
        if(opening=='{' and closing=='}')return true;
         if(opening=='[' and closing==']')return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                stk.push(s[i]);
            }
            else{
                if(!stk.empty() and matching_pairs(stk.top(), s[i])){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};