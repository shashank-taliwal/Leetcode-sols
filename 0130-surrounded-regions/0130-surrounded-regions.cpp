class Solution {
    bool isValid(int x, int y, int rows, int cols){
        if(x<0 or x>=rows or y<0 or y>=cols){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y, set<pair<int,int>>& boundaryNodes){
        visited[x][y]=1;
        cout<<x<<" "<<y<<endl;
        boundaryNodes.insert({x,y});
        int rows=board.size();
        int cols=board[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int x0=x+dx[i];
            int y0=y+dy[i];
            if(isValid(x0,y0,rows,cols) and !visited[x0][y0] and board[x0][y0]=='O'){
                dfs(board,visited,x0,y0,boundaryNodes);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // All we have to do is to find nodes which are located at boundary, store them somewhere and then convert all the remaining nodes
        
        
        set<pair<int,int>> boundaryNodes;
        int rows=board.size();
        int cols=board[0].size();
        
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O' and !visited[i][j] and (i==0 or j==0 or i==rows-1 or j==cols-1)){
                    dfs(board,visited,i,j,boundaryNodes);
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(boundaryNodes.find({i,j})==boundaryNodes.end()){
                    board[i][j]='X';
                }
            }
        }
    }
};