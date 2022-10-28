class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m1;
        bool isOdd=false;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
        }
        for(auto it=m1.begin();it!=m1.end();it++){
            if(it->second%2==1){isOdd=true;break;}
        }
        int ans=0;
        for(auto it=m1.begin();it!=m1.end();it++){
            ans+=((it->second)/2)*2;
        }
        isOdd?ans+=1:ans;
        return ans;
    }
};