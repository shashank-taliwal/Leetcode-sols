class Solution {
        void generateHappyStrings(int n, vector<string>& happyStrings, string curr_string){
                // cout<<curr_string<<endl;
                if(n==1){
                        if(curr_string.back()=='a'){
                                happyStrings.push_back(curr_string+'b');
                                happyStrings.push_back(curr_string+'c');
                        }
                         else if(curr_string.back()=='b'){
                                happyStrings.push_back(curr_string+'a');
                                happyStrings.push_back(curr_string+'c');
                        }
                         else if(curr_string.back()=='c'){
                                happyStrings.push_back(curr_string+'b');
                                happyStrings.push_back(curr_string+'a');
                        }
                        else{
                                happyStrings.push_back(curr_string+'a');
                                 happyStrings.push_back(curr_string+'b');
                                 happyStrings.push_back(curr_string+'c');
                        }
                        return;
                }
                if(curr_string.back()=='a'){
                        generateHappyStrings(n-1,happyStrings,curr_string+'b');
                        generateHappyStrings(n-1,happyStrings,curr_string+'c');
                        return;
                }
                 else if(curr_string.back()=='b'){
                        generateHappyStrings(n-1,happyStrings,curr_string+'a');
                        generateHappyStrings(n-1,happyStrings,curr_string+'c');
                         return;
                }
                 else if(curr_string.back()=='c'){
                        generateHappyStrings(n-1,happyStrings,curr_string+'b');
                        generateHappyStrings(n-1,happyStrings,curr_string+'a');
                         return;
                }
                generateHappyStrings(n-1,happyStrings,curr_string+'a');
                generateHappyStrings(n-1,happyStrings,curr_string+'b');
                generateHappyStrings(n-1,happyStrings,curr_string+'c');
                return;
        }
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n,happyStrings,"");
            sort(happyStrings.begin(),happyStrings.end());
            if(k>happyStrings.size())return "";
            return happyStrings[k-1];
    }
};