class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m1;
        for(string str: strs){
            string str1=str;
            sort(str1.begin(),str1.end());
            m1[str1].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto& it: m1){
            ans.push_back(it.second);
        }
        return ans;
    }
};