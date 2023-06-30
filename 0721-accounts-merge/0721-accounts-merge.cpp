class UnionFind{
    private:
    unordered_map<string,string> parent;
    unordered_map<string,int> size;
    public:
    UnionFind(unordered_set<string>& emails){
        for(string email: emails){
            parent[email]=email;
            size[email]=0;
        }
    }
    string getParent(string mail){
        if(mail==parent[mail]){
            return mail;
        }
        return parent[mail]=getParent(parent[mail]);
    }
    void combine(string mail1, string mail2){
        mail1=getParent(mail1);
        mail2=getParent(mail2);
        
        if(size[mail1]>=size[mail2]){
            parent[mail2]=mail1;
            size[mail1]+=size[mail2];
        }
        else{
            parent[mail1]=mail2;
            size[mail2]+=size[mail1];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_set<string> mails;
        for(vector<string> account: accounts){
            int n=account.size();
            for(int i=1;i<n;i++){
                mails.insert(account[i]);
            }
        }
        unordered_map<string,string> user_mail;
        for(vector<string> account: accounts){
            int n=account.size();
            for(int i=1;i<n;i++){
                user_mail[account[i]]=account[0];
            }
        }
        UnionFind dsu(mails);
        
        for(vector<string> account: accounts){
             int n=account.size();
            for(int i=1;i<n-1;i++){
               dsu.combine(account[i],account[i+1]);
            }
        }
        map<string, vector<string>> user_mails;
        for(string mail: mails){
            string parent=dsu.getParent(mail);
            user_mails[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(auto mail: user_mails){
            string user=user_mail[mail.first];
            vector<string> connected_mails=mail.second;
            vector<string> row;
            row.push_back(user);
            for(string connected_mail: connected_mails){
                row.push_back(connected_mail);
            }
            sort(row.begin()+1,row.end());
            ans.push_back(row);
        }
        return ans;
    }
};