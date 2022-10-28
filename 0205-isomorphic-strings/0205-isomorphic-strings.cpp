class Solution {
        bool util(string s, string t){
                map<char,char> m1;
        for(int i=0;i<s.length();i++){
            if(m1.find(s[i])==m1.end()){
                m1[s[i]]=t[i];
            }
            else{
                if(m1[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
        }
public:
    bool isIsomorphic(string s, string t) {
        return util(s,t) and util(t,s);
    }
};