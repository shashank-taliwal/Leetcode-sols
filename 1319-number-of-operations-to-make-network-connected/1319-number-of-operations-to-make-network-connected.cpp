class UnionFind{
  private:
    vector<int> size, parent;
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
            size[v]+=u;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalCablesRequired=n-1;
        int totalCablesAvailable=connections.size();
        if(totalCablesRequired>totalCablesAvailable){
            return -1;
        }
        UnionFind dsu(n);
        int extraCables=0;
        for(vector<int> connection: connections){
            int x1=connection[0];
            int x2=connection[1];
            
            if(dsu.getParent(x1)!=dsu.getParent(x2)){
                dsu.combine(x1,x2);
            }
            else{
                extraCables++;
            }
        }
        int extraNodes=0;
        for(int i=0;i<n;i++){
            if(dsu.getParent(i)==i){
                extraNodes++;
            }
        }
        if(extraCables>=extraNodes-1){
            return extraNodes-1;
        }
        return -1;
    }
};