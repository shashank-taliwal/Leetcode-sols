class Solution {
public:
    string breakPalindrome(string palindrome) {
        int dusre=0;
        int n=palindrome.length();
            int index=1001;
            if(palindrome.length()==1)return "";
        for(int i=0;i<n;i++){
                if(palindrome[i]!='a'){
                        dusre++;
                        index=min(index,i);
                }
        }
            if(dusre==1 or dusre==0){
                    palindrome[n-1]='b';
            }
            else{
                    palindrome[index]='a';
            }
            return palindrome;
    }
};