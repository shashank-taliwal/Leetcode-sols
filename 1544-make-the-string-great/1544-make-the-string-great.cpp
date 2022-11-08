class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        int n=s.length();
            for(int i=0;i<n;i++){
                            if(!stk.empty() and abs(s[i]-stk.top())==32){
                                    stk.pop();
                            }
                            else{
                                    stk.push(s[i]);
                            }
            }
            string ans;
            while(!stk.empty()){
                    ans+=stk.top();
                    stk.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};