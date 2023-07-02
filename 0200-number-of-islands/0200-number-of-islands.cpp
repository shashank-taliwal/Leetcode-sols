class Solution {
    private:
    bool isValid(int x, int y, int rows, int cols){
        if(x<0 or x>=rows or y>=cols or y<0){
            return false;
        }
        return true;
    }
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y){
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        q.push({x,y});
        visited[x][y]=1;
        while(!q.empty()){
            int x0=q.front().first;
            int y0=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x0+dx[i];
                int y1=y0+dy[i];
                
                if(isValid(x1,y1,rows,cols) and grid[x1][y1]=='1' and !visited[x1][y1]){
                    q.push({x1,y1});
                    visited[x1][y1]=true;
                }
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        //Approach 2 BFS
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        int cc=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' and visited[i][j]==0){
                    cc++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return cc;
    }
};