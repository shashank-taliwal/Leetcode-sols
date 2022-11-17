class Solution {
    void util(string digits, int index, vector<string>& ans, string current){
        if(index>=digits.length()){
            ans.push_back(current);
            return;
        }
        for(int i=0;i<m1[digits[index]].size();i++){
            util(digits,index+1,ans,current+m1[digits[index]][i]);
        }
    }
    void init(){
        m1['2']={'a','b','c'};
        m1['3']={'d','e','f'};
        m1['4']={'g','h','i'};
        m1['5']={'j','k','l'};
        m1['6']={'m','n','o'};
        m1['7']={'p','q','r','s'};
        m1['8']={'t','u','v'};
        m1['9']={'w','x','y','z'};
    }
public:
    map<char,vector<char>> m1;
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return {};
        vector<string> ans;
        init();
        util(digits,0,ans,"");
        return ans;
    }
};