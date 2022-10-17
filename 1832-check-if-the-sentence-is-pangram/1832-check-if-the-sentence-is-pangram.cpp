class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26]={false};
        for(int i=0;i<sentence.length();i++){
            arr[sentence[i]-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(!arr[i]){
                return arr[i];
            }
        }
        return true;
    }
};