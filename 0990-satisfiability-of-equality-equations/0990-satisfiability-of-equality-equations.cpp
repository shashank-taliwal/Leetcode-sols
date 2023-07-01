class UnionFind{
    private:
    unordered_map<string, string> parent;
    unordered_map<string, int> size;
    public:
    UnionFind(set<string>& strs){
        for(string str: strs){
            parent[str]=str;
            size[str]=0;
        }
    }
    string getParent(string u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=getParent(parent[u]);
    }
    void combine(string u, string v){
        u=getParent(u);
        v=getParent(v);
        
        if(size[u]>=size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        set<string> strs;
        for(string equation: equations){
            strs.insert(to_string(equation[0]));
            strs.insert(to_string(equation[3]));
        }
        UnionFind dsu(strs);
        
        for(string equation: equations){
            if(equation[1]=='='){
                dsu.combine(to_string(equation[0]), to_string(equation[3]));
            }
        }
        for(string equation: equations){
            if(equation[1]=='!'){
                if(dsu.getParent(to_string(equation[0]))==dsu.getParent(to_string(equation[3]))){
                    return false;
                }
            }
        }
        return true;
    }
};