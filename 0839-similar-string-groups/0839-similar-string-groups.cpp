class UnionFind{
    private:
    unordered_map<string,string> parent;
    unordered_map<string,int> size;
    public:
    UnionFind(vector<string>& strs){
        for(string str: strs){
            parent[str]=str;
            size[str]=0;
        }
    }
    string getParent(string str){
        if(str==parent[str]){
            return str;
        }
        return parent[str]=getParent(parent[str]);
    }
    void combine(string str1, string str2){
        str1=getParent(str1);
        str2=getParent(str2);
        
        if(size[str1]>size[str2]){
            parent[str2]=str1;
            size[str1]+=size[str2];
        }
        else{
            parent[str1]=str2;
            size[str2]+=size[str1];
        }
    }
};

class Solution {
private:
    bool comp(string str1, string str2){
        int diff=0;
        for(int i=0;i<str1.length(); i++){
            if(str1[i]!=str2[i]){
                diff++;
            }
        }
        return diff==2;
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        UnionFind dsu(strs);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(dsu.getParent(strs[i])!=dsu.getParent(strs[j]) and comp(strs[i], strs[j])){
                    dsu.combine(strs[i],strs[j]);
                }
            }
        }
        unordered_set<string> parents;
        for(string str: strs){
            string parent=dsu.getParent(str);
            parents.insert(parent);
        }
        return parents.size();
    }
};