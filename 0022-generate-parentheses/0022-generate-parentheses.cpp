class Solution {
        void util(int opening, int closing, set<string>& ans, string current){
                if(opening==0 and closing==0){
                        ans.insert(current);
                        return;
                }
                if(opening>0){
                        if(opening==closing){
                                util(opening-1,closing,ans,current+"(");
                        }
                        else if(opening<closing){
                                util(opening-1,closing,ans,current+"(");
                                util(opening,closing-1,ans,current+")");
                        }
                        else{
                                return;
                        }
                }
                else{
                        util(opening,closing-1,ans,current+")");
                }
        }
public:
    vector<string> generateParenthesis(int n) {
        set<string> hashSet;
            vector<string> ans;
         util(n,n,hashSet,"");
            for(string s1:hashSet){
                    ans.push_back(s1);
            }
            return ans;
    }
};