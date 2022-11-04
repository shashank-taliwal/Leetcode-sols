class Solution {
        bool isVowel(char ch){
                if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U'){
                        return true;
                }
                return false;
        }
public:
    string reverseVowels(string s) {
        int n=s.length()-1;
            int left=0,right=n;
            while(left<=right){
                    // cout<<left<<" "<<right<<" "<<s<<endl;
                    if(isVowel(s[left]) and isVowel(s[right])){
                            swap(s[left],s[right]);
                            left++;
                            right--;
                    }
                    else if(!isVowel(s[left]) and !isVowel(s[right])){
                            left++;
                            right--;
                    }
                    else if(isVowel(s[left])){
                            right--;
                    }
                    else if(isVowel(s[right])){
                            left++;
                    }
            }
            return s;
    }
};