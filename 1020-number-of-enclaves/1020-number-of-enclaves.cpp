class Solution {
    bool isValid(int x, int y, int rows, int cols){
        if(x<0 or x>=rows or y<0 or y>=cols){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, set<pair<int,int>>& boundaryNodes, int rows, int cols){
        visited[x][y]=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        boundaryNodes.insert({x,y});
        for(int i=0;i<4;i++){
            int x0=x+dx[i];
            int y0=y+dy[i];
            
            if(isValid(x0,y0,rows,cols) and grid[x0][y0]==1 and !visited[x0][y0]){
                dfs(grid,visited,x0,y0,boundaryNodes,rows,cols);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //The question majorly involves searching for the grid cells that are connected to the boundary
        
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        set<pair<int,int>> boundaryNodes;
        int land=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 and !visited[i][j] and (i==0 or j==0 or i==rows-1 or j==cols-1)){
                    dfs(grid,visited,i,j,boundaryNodes,rows,cols);
                }
                if(grid[i][j]==1){
                   land++; 
                }
            }
        }
        return land-boundaryNodes.size();
    }
};