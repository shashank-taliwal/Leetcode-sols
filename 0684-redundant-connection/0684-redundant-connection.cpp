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
    int getParent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=getParent(parent[u]);
    }
    void combine(int u, int v){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UnionFind dsu(n+1);
        
        for(vector<int> edge: edges){
            int src=edge[0];
            int dest=edge[1];
            
            if(dsu.getParent(dest)!=dsu.getParent(src)){
                dsu.combine(src,dest);
            }
            else{
                return edge;
            }
        }
        return {0,0};
    }
};