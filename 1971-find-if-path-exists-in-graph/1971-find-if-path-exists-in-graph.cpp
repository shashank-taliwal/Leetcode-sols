class UnionFind{
    private:
    vector<int> parent,size;
    public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    
    void combine(int u, int v){
        u=find(u);
        v=find(v);
        
        if(size[u]>size[v]){
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind dsu(n);
        
        for(vector<int> edge: edges){
            dsu.combine(edge[0],edge[1]);
        }
        
        return dsu.find(source)==dsu.find(destination);
    }
};