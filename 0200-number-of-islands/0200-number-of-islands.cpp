class UnionFind{
  private:
    map<pair<int,int>,pair<int,int>> parent;
    map<pair<int,int>,int> size;
    public:
    UnionFind(vector<pair<int,int>> v1){
        for(pair<int,int> p: v1){
            parent[p]=p;
            size[p]=0;
        }
    }
    pair<int,int> getParent(pair<int,int> node){
        if(node==parent[node]){
            return parent[node];
        }
        return parent[node]=getParent(parent[node]);
    }
    void combine(pair<int,int> node1, pair<int,int> node2){
        node1=getParent(node1);
        node2=getParent(node2);
        
        if(size[node1]>=size[node2]){
            size[node1]+=size[node2];
            parent[node2]=node1;
        }
        else{
            size[node2]+=size[node1];
            parent[node1]=node2;
        }
    }
};


class Solution {
public:
    bool isValid(int x, int y, int rows, int cols){
        if(x<0 or x>=rows or y<0 or y>=cols){
            return false;
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Approach3 using Union Find (By union-by-size and Path-compression)
        
        vector<pair<int,int>> coords;
        int rows=grid.size();
        int cols=grid[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    coords.push_back({i,j});
                }
            }
        }
        UnionFind dsu(coords);
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    for(int k=0;k<4;k++){
                        int x0=i+dx[k];
                        int y0=j+dy[k];
                        
                        if(isValid(x0,y0,rows,cols) and grid[x0][y0]=='1'){
                            dsu.combine({i,j},{x0,y0});
                        }
                    }
                }
            }
        }
        set<pair<int,int>> s1;
        for(pair<int,int> coord: coords){
            s1.insert(dsu.getParent(coord));
        }
        return s1.size();
    }
};