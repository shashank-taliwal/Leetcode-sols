class Solution {
        bool isEven(string s){
                if(s.length()>=1 and s[s.length()-1]=='0'){
                        return true;
                }
                return false;
        }
public:
    int numSteps(string s) {
            int ans=0;
            while(true){
                    // cout<<s;
        if(isEven(s)){
                // cout<<" even"<<endl;
                s.pop_back();
        }
            else{
                    // cout<<" odd"<<endl;
                    if(s.length()==1){
                           break;
                    }
                    else{
                            int i;
                            for(i=s.length()-1;i>=0;i--){
                                    if(s[i]=='1'){
                                            s[i]='0';
                                    }
                                    else if(s[i]=='0'){
                                            s[i]='1';
                                            break;
                                    }
                            }
                            if(i<=-1){
                                    string curr="1";
                                    curr+=s;
                                    s=curr;
                            }
                    }
            }
                    ans++;
            }
            return ans;
    }
};