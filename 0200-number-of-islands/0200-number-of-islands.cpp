class Solution {
    bool isValid(int x, int y, int rows, int cols){
        if(x<0 or x>=rows or y<0 or y>=cols){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y){
        visited[x][y]=1;
        int rows=grid.size();
        int cols=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            int x0=x+dx[i];
            int y0=y+dy[i];
            if(isValid(x0,y0,rows,cols) and visited[x0][y0]==0 and grid[x0][y0]=='1'){
                dfs(grid,visited,x0,y0);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // The question is about finding number of connected components
        
        // Approach1 DFS
        
        int rows=grid.size();
        int cols=grid[0].size();
        
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        int cc=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' and visited[i][j]==0 and isValid(i,j,rows,cols)){
                    cc++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return cc;
    }
};