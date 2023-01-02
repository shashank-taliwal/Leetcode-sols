class Solution {
        bool isOperator(string x){
                return x=="+" or x=="-" or x=="*" or x=="/";
        }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n=tokens.size();
            for(int i=0;i<n;i++){
                    if(!isOperator(tokens[i])){
                            stk.push(stoi(tokens[i]));
                    }
                    else{
                            int num1=stk.top();
                            stk.pop();
                            int num2=stk.top();
                            stk.pop();
                            if(tokens[i]=="+"){
                                    stk.push(num2+num1);
                            }
                            if(tokens[i]=="-"){
                                    stk.push(num2-num1);
                            }
                            if(tokens[i]=="*"){
                                    stk.push(num2*num1);
                            }
                            if(tokens[i]=="/"){
                                    stk.push(num2/num1);
                            }
                    }
            }
            return stk.top();
    }
};