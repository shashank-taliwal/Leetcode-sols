class UnionFind{
    private:
     map<vector<int>,vector<int>> parent;
     map<vector<int>, int> size;
    public:
    UnionFind(vector<vector<int>>& stones){
        for(vector<int> stone: stones){
            parent[stone]=stone;
            size[stone]=0;
        }
    }
    vector<int> getParent(vector<int> stone){
        if(stone[0]==parent[stone][0] and stone[1]==parent[stone][1]){
            return stone;
        }
        return parent[stone]=getParent(parent[stone]);
    }
    void combine(vector<int> stone1, vector<int> stone2){
        stone1=getParent(stone1);
        stone2=getParent(stone2);
        
        if(size[stone1]>=size[stone2]){
            parent[stone2]=stone1;
            size[stone1]+=size[stone2];
        }
        else{
            parent[stone1]=stone2;
            size[stone2]+=size[stone1];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        UnionFind dsu(stones);
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    dsu.combine(stones[i],stones[j]);
                }
            }
        }
        
        map<vector<int>,int> lengthOfComponents;
        for(vector<int> stone: stones){
            vector<int> parent=dsu.getParent(stone);
            lengthOfComponents[parent]++;
        }
        int ans=0;
        for(auto it: lengthOfComponents){
            ans+=it.second-1;
        }
        return ans;
    }
};